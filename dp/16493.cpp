#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[25];
int p[25];
int d[25][205];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> p[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= l[i]) {
                d[i][j] = max(d[i-1][j], p[i] + d[i-1][j-l[i]]);
            }
            else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[m][n] << '\n';
}