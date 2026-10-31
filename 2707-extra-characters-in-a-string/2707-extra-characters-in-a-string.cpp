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
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            int idx = ch - 'a';
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    // bool search(string word) {
    //     TrieNode* node = root;
    //     for(char ch:word) {
    //         int idx = ch - 'a';
    //         if(node->children[idx] == nullptr) {
    //             return false;
    //         }
    //         node = node->children[idx];
    //     }
    //     return node->isEnd;
    // }
    // vector<int> totalMatch(string word) {
    //     TrieNode* node = root;
    //     vector<int> indexs;
    //     for(int i=0;i<word.size();i++) {
    //         int idx = word[i] - 'a';
    //         if(node->children[idx] == nullptr) {
    //             return indexs;
    //         }
    //         if(node->isEnd) {
    //             indexs.push_back(i+1);
    //         }
    //         node = node->children[idx];
    //     }
    //     return indexs;
    // }
};
class Solution {
public:
    int countExtra(int idx,string &s,Trie &trie,vector<int> &dp) {
        if(idx == s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int minExtra = 1 + countExtra(idx+1,s,trie,dp);

        TrieNode* node = trie.root;
        for(int i=idx;i<s.size();i++) {
            int index = s[i] - 'a';
            if(node->children[index] == nullptr) break;
            node = node->children[index];
            if(node->isEnd) {
                minExtra = min(minExtra,countExtra(i+1,s,trie,dp));
            }
        }
        
        return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie; 
        int n= s.size();
        for(auto &str:dictionary) {
            trie.addWord(str);
        }
        vector<int> dp(n,-1);
        countExtra(0,s,trie,dp);
        return dp[0];
    }
};