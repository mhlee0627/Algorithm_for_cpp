#include <bits/stdc++.h>
using namespace std;

#define MAX_RANGE 100000

int n, k;
int c[105];
int d[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 0; i <= k; i++) d[i] = MAX_RANGE;

    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= c[i]) {
                d[j] = min(d[j], d[j-c[i]] + 1);
            }
        }
    }

    if (d[k] == MAX_RANGE) cout << -1 << '\n';
    else cout << d[k] << '\n';
    
}