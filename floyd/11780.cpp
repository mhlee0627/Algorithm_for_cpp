#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n, m;
int dist[105][105];
int nxt[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        nxt[a][b] = b;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;

                if (dist[i][j] > (dist[i][k] + dist[k][j])) {
                    dist[i][j] = (dist[i][k] + dist[k][j]);

                    nxt[i][j] = nxt[i][k];
                }
                
                
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << nxt[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << '\n';
            else {
                vector<int> city;
                int cur = i;
                while (cur != j) {
                    city.push_back(cur);
                    cur = nxt[cur][j];
                }
                city.push_back(j);

                cout << city.size() << ' ';
                for (auto elem : city) {
                    cout << elem << ' ';
                }
                cout << '\n';
            }
        }
    }
}