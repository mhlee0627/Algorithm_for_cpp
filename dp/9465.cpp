#include <bits/stdc++.h>
using namespace std;

int t, n;
int board[2][100005];
int d[2][100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		
		d[0][0] = board[0][0];
		d[1][0] = board[1][0];
		d[0][1] = board[0][1] + d[1][0];
		d[1][1] = board[1][1] + d[0][0];
		for (int i = 2; i <= n; i++) {
			d[0][i] = max(d[1][i-1], d[1][i-2]) + board[0][i];
			d[1][i] = max(d[0][i-1], d[0][i-2]) + board[1][i];
		}
	
		cout << max(d[1][n-1], d[0][n-1]) << '\n';
	}
}
