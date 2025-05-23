#include <bits/stdc++.h>
using namespace std;

int n, m;
int money[105][105];
vector<pair<int, int>> adj[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            money[i][j] = 0x3f3f3f3f;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        money[a][b] = min(money[a][b], c);
    }

    for (int i = 1; i <= n; i++) money[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                money[i][j] = min(money[i][j], money[i][k] + money[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (money[i][j] == 0x3f3f3f3f) cout << "0 ";
            else cout << money[i][j] << ' ';
        }
        // cout << '\n';
    }
}