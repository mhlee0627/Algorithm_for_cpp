#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int n;
vector<pair<ll, int>> adj[1005];
bool chk[1005];
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll c;
            cin >> c;

            if (j < i) continue;
            if (c == 0) continue;

            adj[i].push_back({c, j});
            adj[j].push_back({c, i});
        }
    }

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    chk[1] = true;
    for (auto nxt : adj[1]) {
        pq.push({nxt.X, 1, nxt.Y});
    }

    ll cost = 0;

    while (cnt < n-1) {
        ll c;
        int a, b;
        tie(c, a, b) = pq.top();
        pq.pop();

        if (chk[b]) continue;
        chk[b] = true;
        cnt++;
        cost += c;

        for (auto nxt : adj[b]) {
            if (chk[nxt.Y]) continue;
            pq.push({nxt.X, b, nxt.Y});
        }
    }

    cout << cost << '\n';
}
