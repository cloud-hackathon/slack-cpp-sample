#include "slacking.hpp"

#include "json.hpp"
using json = nlohmann::json;


#include <cstdlib>
#include <fstream>

int main() {
    std::string mytoken = std::getenv("SLACK_TOKEN");
    std::string channel = std::getenv("SLACK_CHANNEL");
    std::string username = std::getenv("SLACK_USERNAME");

    auto& slack = slack::create(mytoken);
    slack.chat.channel = channel;

    json j;
    j["text"] = "*bold* `code` _italic_ ~strike~";
    j["channel"] = channel;
    j["username"] = username;
    j["mrkdwn"] = true;
    j["icon_emoji"] = ":princess:";

    slack::post("chat.postMessage", j);

}
