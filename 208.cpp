class Trie {
private:
    vector<Trie *> children;
    bool isEnd;
    Trie * searchPrefix(string prefix)
    {
        Trie *node = this;

        for (char ch : prefix) {
            ch = ch - 'a';
            if (!node->children[ch]) {
                return nullptr;
            }
            node = node->children[ch];
        }

        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26, nullptr), isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *cur = this;
        for (char ch : word) {
            ch = ch - 'a';
            if (cur->children[ch] == nullptr) {
                cur->children[ch] = new Trie();
            }
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */