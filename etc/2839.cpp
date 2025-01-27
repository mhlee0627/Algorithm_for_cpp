#include <bits/stdc++.h>
using namespace std;

int n;
int d[5005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 5000;
    d[2] = 5000;
    d[3] = 1;
    d[4] = 5000;
    d[5] = 1;
    for (int i = 6; i <= n; i++) {
            d[i] = min(d[i-3], d[i-5]) + 1;
    }

    if (d[n] >= 5000) {
        cout << -1;
    }
    else {
        cout << d[n];
    }
}