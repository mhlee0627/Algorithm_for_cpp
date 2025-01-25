#include <bits/stdc++.h>
using namespace std;

int n;
int board[501][501];
int d[501][501];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> board[i-1][j];
        }
    }

    d[0][0] = board[0][0];
    d[1][0] = board[1][0] + d[0][0];
    d[1][1] = board[1][1] + d[0][0];
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + board[i][j];
            // cout << "(" << i << ", " << j << ") " << d[i][j] << "\n"; 
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << d[4][i] << " ";
    // }

    int max = d[n-1][0];
    for (int i = 1; i < n; i++) {
        max = max > d[n-1][i] ? max : d[n-1][i];
    }
    
    cout << max;
}