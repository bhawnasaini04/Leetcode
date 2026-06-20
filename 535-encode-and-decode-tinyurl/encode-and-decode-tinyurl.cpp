class Solution {
public:
    unordered_map<string, string> mp;
    string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string encode(string longUrl) {

        string key;

        do {
            key.clear();

            for (int i = 0; i < 6; i++) {
                key += chars[rand() % chars.size()];
            }

        } while (mp.count(key));

        mp[key] = longUrl;

        return "http://tinyurl.com/" + key;
    }

    string decode(string shortUrl) {

        string key =
            shortUrl.substr(
                shortUrl.find_last_of('/') + 1
            );

        return mp[key];
    }
};