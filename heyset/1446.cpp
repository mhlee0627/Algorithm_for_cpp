
#include <bits/stdc++.h>
using namespace std;

int n, d;
int dp[10005];
vector<pair<int, int>> vec[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    int s = 0;
    int e = 0;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s >> e >> c;
        if (e > d || (e-s) <= c) continue;

        vec[e].push_back({s, c});
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= d; i++) {
        int min_v = 10005;
        for (auto elem : vec[i]) {
            min_v = min(min_v, dp[elem.first] + elem.second);
        }
        dp[i] = min(dp[i-1]+1, min_v);
    }

    cout << dp[d] << '\n';
}