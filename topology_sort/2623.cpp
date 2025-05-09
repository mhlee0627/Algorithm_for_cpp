#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
int deg[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    int cnt;
    for (int i = 0; i < m; i++) {
        cin >> cnt;
        
        if (cnt == 0) {
            continue;
        }
        else {
            int pre;
            cin >> pre;
            cnt--;
            while (cnt--) {
                int cur;
                cin >> cur;
                adj[pre].push_back(cur);
                deg[cur]++;
                pre = cur;
            }
        }
    }

    queue<int> q;
    vector<int> ret;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ret.push_back(cur);

        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    if (ret.size() == n) {
        for (auto elem : ret) {
            cout << elem << '\n';
        }
    }
    else {
        cout << 0 << '\n';
    }

}