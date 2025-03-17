#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[105];
int v[105];
int d[105][100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int y = 1; y <= k; y++) {
        for (int i = 1; i <= n; i++) {
            if (w[i] <= y) {
                int tmp = y - w[i];
                d[i][y] = max(d[i-1][y], v[i] + d[i-1][tmp]);
            }
            else {
                d[i][y] = d[i-1][y];                
            }
        }
    }

    cout << d[n][k] << '\n';
}