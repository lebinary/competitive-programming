#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
  public:
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<vector<int>>> posts;
    int t;
    int FEED_LIMIT;

    Twitter() {
        this->t = 0;
        this->FEED_LIMIT = 10;
    }

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({t, userId, tweetId});
        t++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<tuple<vector<int>, int>> maxHeap;

        if (!posts[userId].empty()) {
            maxHeap.push({posts[userId].back(), posts[userId].size() - 1});
        }
        for (int followeeId : follows[userId]) {
            if (!posts[followeeId].empty()) {
                maxHeap.push({posts[followeeId].back(), posts[followeeId].size() - 1});
            }
        }

        while (!maxHeap.empty() && feed.size() < FEED_LIMIT) {
            auto [top, lastIdx] = maxHeap.top();
            int uId = top[1], tweetId = top[2];
            maxHeap.pop();
            feed.push_back(tweetId);

            if (lastIdx > 0) {
                maxHeap.push({posts[uId][lastIdx - 1], lastIdx - 1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) { follows[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { follows[followerId].erase(followeeId); }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
