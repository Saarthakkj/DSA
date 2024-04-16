class Twitter {
public:
    map<int , set<int>> friends ; 
    int curr = 0 ; 
    //need a max heap to implement tweet from the last 10 posts
    priority_queue<vector<int> > time_line ; 
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        time_line.push({curr++ , userId , tweetId}) ; 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> userTimeline = time_line; // Copy timeline

        int n = 0;
        while (!userTimeline.empty() && n < 10) {
            auto top_twt = userTimeline.top();
            userTimeline.pop();

            int tweetUserId = top_twt[1];
            int tweetId = top_twt[2];

            // Check if the tweet author is the user or a friend of the user
            if (tweetUserId == userId || friends[userId].count(tweetUserId) > 0) {
                ans.push_back(tweetId);
                n++;
            }
        }
        return ans;
    }

    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId) ; 
    }
    
    void unfollow(int followerId, int followeeId) {
    // Check if the follower is following the followee
        if (friends.count(followerId) && friends[followerId].count(followeeId)) {
            friends[followerId].erase(followeeId);
        }
    }

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */