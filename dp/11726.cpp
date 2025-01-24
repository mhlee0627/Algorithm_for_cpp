#include <bits/stdc++.h>
using namespace std;

int d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[0] = 1;
    d[1] = 2;
    for (int i = 2; i < n; i++) {
        d[i] = d[i-1] + d[i-2];
        d[i]%=10007;
    }

    cout << d[n-1] << "\n";
}