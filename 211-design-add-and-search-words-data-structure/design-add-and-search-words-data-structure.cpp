class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(string word, int index, TrieNode* node) {
        if(index == word.size())
            return node->isEnd;

        char ch = word[index];

        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] &&
                   searchHelper(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        int idx = ch - 'a';

        if(node->children[idx] == NULL)
            return false;

        return searchHelper(word, index + 1, node->children[idx]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->children[idx] == NULL)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};