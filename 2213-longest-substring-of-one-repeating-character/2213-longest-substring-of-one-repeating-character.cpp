class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int len;
        int prefix, suffix, best;

        Node() {
            leftChar = rightChar = '#';
            len = prefix = suffix = best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Best answer is either completely in left/right
        res.best = max(a.best, b.best);

        // Calculate prefix
        res.prefix = a.prefix;

        if (a.prefix == a.len &&
            a.rightChar == b.leftChar) {

            res.prefix = a.len + b.prefix;
        }

        // Calculate suffix
        res.suffix = b.suffix;

        if (b.suffix == b.len &&
            a.rightChar == b.leftChar) {

            res.suffix = b.len + a.suffix;
        }

        // Repeating substring crossing the middle
        if (a.rightChar == b.leftChar) {

            res.best = max(res.best,
                           a.suffix + b.prefix);
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {

            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(s, 2 * node, l, mid);
        build(s, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    void update(int node, int l, int r,
                int idx, char ch) {

        if (l == r) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        // Build segment tree
        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            // Update character
            update(1, 0, n - 1, idx, ch);

            // Root contains answer for entire string
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};