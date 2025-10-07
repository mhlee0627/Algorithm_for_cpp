#include <bits/stdc++.h>
using namespace std;

int n, k;
int l[1005];
int g[1005];
int d[1005][10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> g[i] >> l[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= l[i]) {
                d[i][j] = max(d[i-1][j], g[i] + d[i-1][j-l[i]]);
            }
            else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[k][n] << '\n';
}