#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[15][1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 10; i++) dp[i][1] = 1;

    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][k] += dp[j][k-1] % 10007;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++) sum += dp[i][n] % 10007;

    cout << sum % 10007 << '\n';
}