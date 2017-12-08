all:
	clang++ -g -Wall -std=c++11 -stdlib=libc++ -I slacking/include/slacking -lcurl -o slack_pingpong slack_pingpong.cpp
