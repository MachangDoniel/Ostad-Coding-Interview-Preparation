#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int val;
    int left, right;
};

void in_order(int idx, vector<Node>& tree, vector<int>& result) {
    if (idx == -1) return;
    in_order(tree[idx].left, tree, result);
    result.push_back(tree[idx].val);
    in_order(tree[idx].right, tree, result);
}

void pre_order(int idx, vector<Node>& tree, vector<int>& result) {
    if (idx == -1) return;
    result.push_back(tree[idx].val);
    pre_order(tree[idx].left, tree, result);
    pre_order(tree[idx].right, tree, result);
}

void post_order(int idx, vector<Node>& tree, vector<int>& result) {
    if (idx == -1) return;
    post_order(tree[idx].left, tree, result);
    post_order(tree[idx].right, tree, result);
    result.push_back(tree[idx].val);
}

int32_t main() {
    int n;
    cin >> n;
    vector<Node> tree(n);

    for (int i = 0; i < n; ++i) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
    }

    vector<int> in, pre, post;

    in_order(0, tree, in);
    pre_order(0, tree, pre);
    post_order(0, tree, post);

    for (int x : in) cout << x << " "; cout << "\n";
    for (int x : pre) cout << x << " "; cout << "\n";
    for (int x : post) cout << x << " "; cout << "\n";

    return 0;
}
