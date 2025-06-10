#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<int> adj[55];
int rev_parent[55];
int root;

int parent[55];
bool check_leaf[55];
bool check_rev_leaf[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) {
            root = i;
            continue;
        }

        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }
    cin >> r;

    if (root == r) {
        cout << 0 << '\n';
        return 0;
    }

    int remove_parent = parent[r];
    // cout << "remove_parent: " << remove_parent << '\n';
    for (int i = 0; i < n; i++) rev_parent[i] = -1;

    queue<int> q;
    q.push(root);
    rev_parent[root] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (rev_parent[cur] == nxt) continue;
            if (nxt == r) continue;
            q.push(nxt);
            rev_parent[nxt] = cur;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << rev_parent[i] << ' ';
    // }
    // cout << '\n';

    int rev_node_cnt = 0;
    int rev_parent_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (rev_parent[i] == -1) continue;

        rev_node_cnt++;
        check_rev_leaf[rev_parent[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (check_rev_leaf[i]) rev_parent_cnt++;
    }

    // cout << "rev_node_cnt: " << rev_node_cnt << '\n';
    // cout << "rev_parent_cnt: " << rev_parent_cnt << '\n';
    cout << rev_node_cnt + 1 - rev_parent_cnt << '\n';

}