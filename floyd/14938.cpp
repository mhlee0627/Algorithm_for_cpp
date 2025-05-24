#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

int n, m, r;
int item[105];
int dist[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    
    for (int i = 1; i <= n; i++) cin >> item[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = INF;
        }
    }

    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        int sum = item[i];
        for (int j = 1; j <= n; j++) {
            if (i != j && dist[i][j] <= m) {
                sum += item[j];
                // cout << "sum: " << sum << ' ' << i << ' ' << j << '\n';
            }
        }
        maxv = max(maxv, sum);
    }

    cout << maxv << '\n';
}