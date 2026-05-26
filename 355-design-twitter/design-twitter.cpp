class Twitter {
private:
    int time = 0;

    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;

        followMap[userId].insert(userId);

        for(int followee : followMap[userId]) {

            auto &t = tweets[followee];

            if(!t.empty()) {
                int idx = t.size()-1;

                pq.push({
                    t[idx].first,
                    t[idx].second,
                    followee,
                    idx
                });
            }
        }

        vector<int> result;

        while(!pq.empty() && result.size()<10) {

            auto top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            result.push_back(tweetId);

            if(idx>0) {
                idx--;

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};