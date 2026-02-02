#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    // Global time to maintain tweet order
    int timeStamp;

    // userId -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followees;

public:
    Twitter() {
        timeStamp = 0;
    }

    // User posts a tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // Retrieve 10 most recent tweets
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // Max heap: {time, tweetId}
        priority_queue<pair<int,int>> pq;

        // User should see their own tweets
        followees[userId].insert(userId);

        // Push all tweets from followees
        for (int followee : followees[userId]) {
            if (tweets.count(followee)) {
                for (auto &t : tweets[followee]) {
                    pq.push(t);
                }
            }
        }

        // Extract top 10 tweets
        int count = 0;
        while (!pq.empty() && count < 10) {
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return result;
    }

    // Follower follows followee
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    // Follower unfollows followee
    void unfollow(int followerId, int followeeId) {
        // Cannot unfollow self
        if (followerId == followeeId) return;

        if (followees.count(followerId)) {
            followees[followerId].erase(followeeId);
        }
    }
};
