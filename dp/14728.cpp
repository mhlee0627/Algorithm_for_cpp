#include <bits/stdc++.h>
using namespace std;

int n, t;
int l[1005];
int s[1005];
int d[105][10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (j >= l[i]) {
                d[i][j] = max(d[i-1][j], s[i] + d[i-1][j-l[i]]);
            }
            else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[n][t] << '\n';
}
