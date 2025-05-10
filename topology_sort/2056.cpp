#include <bits/stdc++.h>
using namespace std;

int n;
int wh[10001];
vector<int> adj[10001];
int deg[10001];
int ret[10001];
int tsum;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> wh[i];
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int in;
            cin >> in;
            adj[in].push_back(i);
            deg[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
        ret[i] = wh[i];
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            ret[nxt] = max(ret[nxt], ret[cur] + wh[nxt]);

            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ret[i]);
    }

    cout << ans << '\n';
}