#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int coin[25];
uint32_t dp[25][10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> coin[i];
        cin >> m;

        for (int i = 1; i <= n; i++) dp[i][0] = 1;

        for (int c = 1; c <= n; c++) {
            for (int k = 1; k <= m; k++) {
                if (k >= coin[c]) {
                    dp[c][k] = dp[c][k - coin[c]] + dp[c-1][k];
                }
                else {
                    dp[c][k] = dp[c-1][k];
                }
            }
        }

        cout << dp[n][m] << '\n';
    }
}