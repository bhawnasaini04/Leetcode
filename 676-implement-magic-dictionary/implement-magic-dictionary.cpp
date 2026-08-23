class MagicDictionary {
public:
    vector<string> words;

    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }

    bool search(string searchWord) {

        for (string word : words) {

            // Length must be same
            if (word.size() != searchWord.size())
                continue;

            int difference = 0;

            for (int i = 0; i < word.size(); i++) {

                if (word[i] != searchWord[i])
                    difference++;
            }

            // Exactly one character should be different
            if (difference == 1)
                return true;
        }

        return false;
    }
};