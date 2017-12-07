all: post.cpp
	clang++ -std=c++11 -stdlib=libc++ -I slacking/include/slacking -lcurl -o slack_post post.cpp
