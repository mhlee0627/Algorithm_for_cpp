#include <bits/stdc++.h>
using namespace std;

#define H 1
#define V 2
#define D 3

int n;
int board[18][18];
int ret;

bool check_bound(int nx, int ny) {
	return (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	queue<tuple<int, int, int>> q;
	q.push({H, 0, 1});

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (get<1>(cur) == n-1 && get<2>(cur) == n-1) {
			ret++;
		}

		int state = get<0>(cur);
		if (state == H) {
			int nx = get<1>(cur);
			int ny = get<2>(cur) + 1;
			if (check_bound(nx, ny)) {
				q.push({state, nx, ny});
				if (check_bound(nx+1, ny) && check_bound(nx+1, ny-1)) {
					q.push({D, nx+1, ny});
				}
			}
		}
		else if (state == V) {	
			int nx = get<1>(cur) + 1;
			int ny = get<2>(cur);
			if (check_bound(nx, ny)) {
				q.push({state, nx, ny});
				if (check_bound(nx, ny+1) && check_bound(nx-1, ny+1)) {
					q.push({D, nx, ny+1});
				}
			}
		}
		else {
			bool c1 = false;
			bool c2 = false;
			if (check_bound(get<1>(cur) + 1, get<2>(cur))) {
				q.push({V, get<1>(cur) + 1, get<2>(cur)});
				c1 = true;
			}

			if (check_bound(get<1>(cur), get<2>(cur)+1)) {
				q.push({H, get<1>(cur), get<2>(cur)+1});
				c2 = true;
			}

			if (c1 && c2 && check_bound(get<1>(cur)+1, get<2>(cur)+1)) {
				q.push({D, get<1>(cur)+1, get<2>(cur)+1});
			}
		}
	}

	cout << ret << '\n';
}
