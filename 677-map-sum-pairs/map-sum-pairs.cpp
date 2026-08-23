class MapSum {
public:
    unordered_map<string, int> mp;

    MapSum() {
    }

    void insert(string key, int val) {
        mp[key] = val;
    }

    int sum(string prefix) {

        int answer = 0;

        for (auto x : mp) {

            string key = x.first;

            // Check if key starts with prefix
            if (key.substr(0, prefix.size()) == prefix) {
                answer += x.second;
            }
        }

        return answer;
    }
};