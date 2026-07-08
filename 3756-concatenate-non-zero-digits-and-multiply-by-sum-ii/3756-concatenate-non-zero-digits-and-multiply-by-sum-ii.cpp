class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        int cnt;
        long long sum;
        long long val;
    };

    vector<Node> seg;
    vector<long long> pow10;
    string s;
    int n;

    Node merge(Node a, Node b) {
        return {
            a.cnt + b.cnt,
            a.sum + b.sum,
            (a.val * pow10[b.cnt] + b.val) % MOD
        };
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[idx] = {0, 0, 0};
            else
                seg[idx] = {1, d, d};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        n = s.size();

        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        seg.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};