class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool searchDot(string word, TrieNode* root) {
        TrieNode* node = root;
        for(int i = 0;i<word.size();i++) {
            int idx = word[i] - 'a';
            if(word[i] == '.') {
                for(int j=0;j<26;j++) {
                    if(node->children[j] !=nullptr && searchDot(word.substr(i+1,word.size() - i),node->children[j]) ) {
                        return true;
                    }
                } 
                return false;
            }
            if(node->children[idx] == nullptr) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    bool search(string word) {
        return searchDot(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */