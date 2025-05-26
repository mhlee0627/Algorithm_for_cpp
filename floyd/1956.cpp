#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int v, e;
int dist[405][405];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // cout << "print:\n";
    // for (int i = 1; i <= v; i++) {
    //     for (int j = 1; j <= v; j++) {
    //         if (dist[i][j] == INF) cout << 0 << ' ';
    //         else cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int ret = INF;
    for (int i = 1; i <= v; i++) {
        ret = min(ret, dist[i][i]);
    }

    if (ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';
}