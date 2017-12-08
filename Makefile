all:
	/usr/bin/g++-4.9 -g -Wall -std=c++11 -I slacking/include/slacking -o slack_pingpong slack_pingpong.cpp -lcurl
#	clang++ -g -Wall -std=c++11 -stdlib=libc++ -I slacking/include/slacking -lcurl -o slack_pingpong slack_pingpong.cpp
