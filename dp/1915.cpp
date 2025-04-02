#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1005];
int d[1005][1005];

void print() {
	cout << "print\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> board[i];
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j-1] == '0') {
				d[i][j] = 0;
			}
			else {
				d[i][j] = min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1]) + 1;
			}
		}
	}
	
	int max_v = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			max_v = max(max_v, d[i][j]);
		}
	}

	cout << max_v*max_v << '\n';
}	
