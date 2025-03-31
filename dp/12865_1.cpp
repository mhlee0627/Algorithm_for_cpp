#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[105];
int v[105];
int d[100005][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int wi = 1; wi <= k; wi++) {
        for (int i = 1; i <= n; i++) {
            if (wi >= w[i]) {
                d[wi][i] = max(d[wi][i-1], d[wi-w[i]][i-1] + v[i]);
            }
            else {
                d[wi][i] = d[wi][i-1];
            }
        }
    }

    cout << d[k][n] << '\n';
}