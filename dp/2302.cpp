#include <bits/stdc++.h>
using namespace std;

int n, m;
int vip[50];
int d[50];
int ret = 1;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> vip[i];

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i-1] + d[i-2];
    }

    if (m == 0) {
        cout << d[n] << '\n';
        return 0;
    }

    int cur = 0;
    for (int i = 0; i < m; i++) {
        ret *= d[vip[i]-cur-1];
        cur = vip[i];
    }
    ret *= d[n-cur];

    cout << ret << '\n';
}