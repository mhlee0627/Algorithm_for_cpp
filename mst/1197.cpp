#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[100005];
bool chk[100005];
int cnt;
int minv;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = 1;

    for (auto elem : adj[1]) {
        pq.push({elem.X, 1, elem.Y});
    }

    while (cnt < v-1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();

        if (chk[b]) continue;
        chk[b] = 1;
        cnt++;
        minv += cost;

        for (auto elem : adj[b]) {
            if (chk[elem.Y]) continue;
            pq.push({elem.X, b, elem.Y});
        }
    }

    cout << minv << '\n';
}