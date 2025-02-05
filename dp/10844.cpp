#include <bits/stdc++.h>
using namespace std;

int n;
long long d[101][10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1][0] = 0;
    d[1][1] = 1;
    d[1][2] = 1;
    d[1][3] = 1;
    d[1][4] = 1;
    d[1][5] = 1;
    d[1][6] = 1;
    d[1][7] = 1;
    d[1][8] = 1;
    d[1][9] = 1;

    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i-1][1] % 1000000000;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 1000000000;
        d[i][2] = (d[i-1][1] + d[i-1][3]) % 1000000000;
        d[i][3] = (d[i-1][2] + d[i-1][4]) % 1000000000;
        d[i][4] = (d[i-1][3] + d[i-1][5]) % 1000000000;
        d[i][5] = (d[i-1][4] + d[i-1][6]) % 1000000000;
        d[i][6] = (d[i-1][5] + d[i-1][7]) % 1000000000;
        d[i][7] = (d[i-1][6] + d[i-1][8]) % 1000000000;
        d[i][8] = (d[i-1][7] + d[i-1][9]) % 1000000000;
        d[i][9] = d[i-1][8] % 1000000000;
    }

    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += d[n][i];
    }
    cout << sum % 1000000000 << '\n';
}