#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> st_order;
vector<int> vec_list[405];
int board[25][25];
vector<pair<int, int>> pre_list;
pair<int, int> pre[25][25];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void print_brd() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_pre() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << pre[i][j].first << ',' << pre[i][j].second << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void check_action1(int cur) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) {
				pre[i][j] = {0, 0};
				continue;
			}

			int cnt = 0;
			int e_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = dirX[k] + i;
				int ny = dirY[k] + j;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				for (auto elem : vec_list[cur]) {
					if (board[nx][ny] == elem) cnt++;
				}

				if (board[nx][ny] == 0) e_cnt++;
			}
			pre[i][j].first = cnt;
			pre[i][j].second = e_cnt;
			pre_list.push_back({cnt, e_cnt});
		}
	}
}

void check_action2(int cur) {
	sort(pre_list.begin(), pre_list.end(), greater<pair<int, int>>());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0) continue;
			if (pre[i][j] == pre_list[0]) {
				board[i][j] = cur;
				return;
			}
		}
	}
}

int get_score() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = dirX[k] + i;
				int ny = dirY[k] + j;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				for (auto elem : vec_list[board[i][j]]) {
					if (board[nx][ny] == elem) cnt++;
				}
			}

			if (cnt == 1) sum++;
			else if (cnt == 2) sum += 10;
			else if (cnt == 3) sum += 100;
			else if (cnt == 4) sum += 1000;
		}
	}

	return sum;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int st, tmp;
	for (int i = 1; i <= n*n; i++) {
		cin >> st;
		st_order.push_back(st);
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			vec_list[st].push_back(tmp);
		}
	}

	for (auto order : st_order) {
		check_action1(order);
		check_action2(order);
		pre_list.clear();
		//print_brd();
	}

	cout << get_score() << '\n';
}
