#include <bits/stdc++.h>
using namespace std;

#define UP 0
#define RT 1
#define DW 2
#define LF 3

int n, r;
int board[1000][1000];

void print_brd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check_bound(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;

	int x = n/2;
	int y = n/2;
	int cur = 1;
	board[x][y] = cur;
	
	int gap = 1;
	int gap_rp = 0;
	int dir = UP;

	while (1) {
		switch (dir) {
			case UP:
			{
				for (int i = 0; i < gap; i++) {
					x--;
					if (!check_bound(x, y)) break;
					board[x][y] = ++cur;
				}
				break;
			}	
			case RT:
			{
				for (int i = 0; i < gap; i++) {
					y++;
					if (!check_bound(x, y)) break;
					board[x][y] = ++cur;
				}
				break;
			}
			case DW:
			{
				for (int i = 0; i < gap; i++) {
					x++;
					if (!check_bound(x, y)) break;
					board[x][y] = ++cur;
				}
				break;
			}	
			case LF:
			{
				for (int j = 0; j < gap; j++) {
					y--;
					if (!check_bound(x, y)) break;
					board[x][y] = ++cur;
				}
				break;
			}
		}

		if (!check_bound(x, y)) break;

		dir = (++dir)%4;
		gap_rp++;

		if (gap_rp == 2) {
			gap_rp = 0;
			gap++;
		}
	}

	print_brd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == r) cout << i+1 << ' ' << j+1 << '\n';
		}
	}
}

