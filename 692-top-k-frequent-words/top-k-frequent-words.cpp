class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> frequency;

        // Count frequency
        for (string word : words) {
            frequency[word]++;
        }

        vector<string> uniqueWords;

        for (auto x : frequency) {
            uniqueWords.push_back(x.first);
        }

        // Sort words
        sort(uniqueWords.begin(), uniqueWords.end(),
            [&](string a, string b) {

                if (frequency[a] != frequency[b])
                    return frequency[a] > frequency[b];

                return a < b;
            });

        // Take first k words
        vector<string> answer;

        for (int i = 0; i < k; i++) {
            answer.push_back(uniqueWords[i]);
        }

        return answer;
    }
};
