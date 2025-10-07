#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<int, int>> adj[305];
bool chk[305];
int cnt;
int ret;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        adj[i].push_back({w, 0});
        adj[0].push_back({w, i});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            if (j < i) continue;
            if (c == 0) continue;

            adj[i].push_back({c, j});
            adj[j].push_back({c, i});
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    for (auto nxt : adj[1]) {
        pq.push({nxt.X, 1, nxt.Y});
    }
    chk[1] = true;

    while (cnt < n) {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b]) continue;

        cnt++;
        chk[b] = true;
        ret += cost;

        for (auto nxt : adj[b]) {
            if (chk[nxt.Y]) continue;
            pq.push({nxt.X, b, nxt.Y});
        }
    }

    cout << ret << '\n';
}

