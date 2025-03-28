#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[105];
int v[105];
// d[무게][물건]
int d[100005][105]; 

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= w[j]) {
                d[i][j] = max(d[i][j-1], d[i-w[j]][j-1] + v[j]);
            }
            else {
                d[i][j] = d[i][j-1];
            }
        }
    }

    cout << d[k][n] << '\n';
}