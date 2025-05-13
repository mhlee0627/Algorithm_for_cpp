#include <bits/stdc++.h>
using namespace std;

// d[Tree][Time][Move]
int d[3][1001][32];
int tree[1001];
int t, w;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for (int i = 1; i <= t; i++) cin >> tree[i];

    if (tree[1] == 1) {
        d[1][1][1] = 1;
    }
    else {
        d[2][1][2] = 1;
    }

    for (int i = 2; i <= t; i++) {
        for (int mv = 1; mv <= w+1; mv++) {
            if (tree[i] == 1) {
                d[1][i][mv] = max(d[1][i-1][mv], d[2][i-1][mv-1]) + 1;
                d[2][i][mv] = max(d[1][i-1][mv-1], d[2][i-1][mv]);
            }
            else {
                d[1][i][mv] = max(d[1][i-1][mv], d[2][i-1][mv-1]);
                d[2][i][mv] = max(d[1][i-1][mv-1], d[2][i-1][mv]) + 1;
            }
        }
    }

    int ret = -1;
    for (int i = 1; i <= w+1; i++) {
        ret = max({ret, d[1][t][i], d[2][t][i]});
    }
    cout << ret << '\n';
}