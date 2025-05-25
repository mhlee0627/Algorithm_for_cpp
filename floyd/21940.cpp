#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, m, k;
vector<int> frpos;
int dist[205][205];

void print() {
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;

        dist[s][e] = t;
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int pos;
        cin >> pos;
        frpos.push_back(pos);
    }

    for (int z = 1; z <= n; z++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;

                if (dist[i][j] > (dist[i][z] + dist[z][j])) {
                    dist[i][j] = dist[i][z] + dist[z][j];
                }
            }
        }
    }

    vector<pair<int, int>> ret;
    for (int x = 1; x <= n; x++) {
        int mx = 0;
        for (auto pos : frpos) {
            if (pos == x) continue;

            mx = max(mx, dist[x][pos] + dist[pos][x]);
        }

        ret.push_back({mx, x});
    }
    sort(ret.begin(), ret.end());

    int mn = ret[0].first;
    for (auto elem : ret) {
        if (mn < elem.first) break;
        cout << elem.second << ' ';
    }
    cout << '\n';
}