#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[105];
int d[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> c[i];

    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= c[i]) {
                d[j] += d[j - c[i]];
            }
        }
    }

    cout << d[k] << '\n';
}