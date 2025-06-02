#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

#define X first
#define Y second

int n, m, x;
vector<pair<int, int>> adj[1005];
int dist[1005];
vector<int> gotime;

void clear_dist() {
    for (int i = 0; i <= n; i++) dist[i] = INF;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }


    for (int i = 1; i <= n; i++) {
        clear_dist();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[i] = 0;
        pq.push({dist[i], i});

        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            if (dist[cur.Y] != cur.X) continue;

            for (auto nxt : adj[cur.Y]) {
                if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }

        gotime.push_back(dist[x]);
    }

    clear_dist();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({dist[x], x});

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }

    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        maxv = max(maxv, (gotime[i-1] + dist[i]));
    }

    cout << maxv << '\n';
}