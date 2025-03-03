#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1025][1025];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			board[i][j] = tmp + board[i][j-1];
		}
	}

	int s1, s2, e1, e2;
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2 >> e1 >> e2;

		int sum = 0;
		for (int s = s1; s <= e1; s++) {
			sum += (board[s][e2] - board[s][s2-1]);
		}

		cout << sum << '\n';
	}
}
