#include "slacking.hpp"

#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <unistd.h>

int main() {
    std::string slack_token = std::getenv("SLACK_TOKEN");
    std::string channel = std::getenv("SLACK_CHANNEL");
    std::string username = std::getenv("SLACK_USERNAME");

    std::time_t start_time = std::time(NULL);

    // create slack connection with token
    auto& slack = slack::create(slack_token);
    slack.chat.channel = channel;

    // search channelID from its name
    json getChannelID;
    getChannelID["token"] = slack_token;
    getChannelID["types"] = "public_channel,private_channel,mpim,im";
    getChannelID["limit"] = 100;

    std::string channelID;
    json channels = slack::post("conversations.list", getChannelID);
    for (auto& element : channels["channels"]) {
        if (element["name"] == channel) {
	     channelID = element["id"];
	}
    }

    std::cout << "channel: " << channel << " (" << channelID << ")" << std::endl;


    json getChannelHistory;
    getChannelHistory["token"] = slack_token;
    getChannelHistory["channel"] = channelID;
    getChannelHistory["oldest"] = start_time;

    json pong;
    pong["text"] = "*pong*";
    pong["channel"] = channel;
    pong["username"] = username;
    pong["mrkdwn"] = true;
    pong["icon_emoji"] = ":princess:";
    
    json messages;

    // main loop; check new arrival message, if the text matches, reply
    while(true) {
        messages = slack::post("conversations.history", getChannelHistory);
        for (auto& element : messages["messages"]) {
	    // you may do smehitng here
	    if (element["type"] == "message" and element["text"] == "ping") {        
                slack::post("chat.postMessage", pong);
	    }
	    if (getChannelHistory["oldest"] < element["ts"]) {
	        getChannelHistory["oldest"] = element["ts"];
	    }
        }
	sleep(5);
    }
}
