# C++ sample for Slack

C++ から Slack Web API を call する サンプルです

## requirement

Slack Web API を call するための library として [slacking](https://github.com/coin-au-carre/slacking) を利用しています
同ライブラリの requirement として下記があります

* C++11 compatible compiler. (tested with clang 9.0)
* [libcurl](https://curl.haxx.se/libcurl/)

## Get start

1. https://api.slack.com/bot-users のcreating a new bot userをクリックして新しくBotを作成します
2. 適当なチャンネルに1.で作成したBotをInviteします
3. Botを動かすマシンに環境変数をセットします

```sh
$ export SLACK_TOKEN=<1.で取得したTOKEN>
$ export SLACK_USERNAME=<1.で設定したBot Name>
$ export SLACK_CHANNEL=<2. inviteしたchannel name>
```

4. botをビルドして起動する

```sh
$ git clone https://github.com/cloud-hackathon/slack-cpp-sample.git
$ cd slack-cpp-sample
$ git submodule update --init --recursive
$ make
$ ./slack_pingpong
```

5. 動作確認

ボットの動作しているchannel で `ping` と発言すると bot が `pong` と応答するはずです

## 拡張してみよう

本サンプルでは、slacking の 提供する `slack::post` `slack::get` を用いて
Slack Web API を call しています。
Web API の任意の method に任意の json を投げ込めますので、下記API referenceを
参照して拡張してみましょう！

https://api.slack.com/web




