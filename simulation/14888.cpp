#include <bits/stdc++.h>
using namespace std;

int n;
int num[12];
int op_cnt[4];
vector<char> op;
char op_ret[12];
bool vis[12];
vector<int> cal_ret;

int cal() {
	int cnt = num[0];
	for (int i = 1; i < n; i++) {
		if (op_ret[i-1] == '+') {
			cnt += num[i];
		}
		else if (op_ret[i-1] == '-') {
			cnt -= num[i];
		}
		else if (op_ret[i-1] == '*') {
			cnt *= num[i];
		}
		else {
			cnt /= num[i];
		}
	}

	//cout << "cnt: " << cnt << '\n';
	return cnt;
}

void set_op() {
	for (int i = 0; i < 4; i++) {
		int cnt = op_cnt[i];
		char c;
		if (i == 0) c = '+';
		else if (i == 1) c = '-';
		else if (i == 2) c = '*';
		else c = '/';

		for (int j = 0; j < op_cnt[i]; j++) {	
			op.push_back(c);
		}
	}
}

void bt(int k) {
	if (k == n-1) {
		//for (int i = 0; i < k; i++) {
		//	cout << op_ret[i] << ' ';
		//}
		//cout << '\n';
		cal_ret.push_back(cal());
		return;
	}

	char tmp = 0;
	for (int i = 0; i < n-1; i++) {
		if (!vis[i] && tmp != op[i]) {
			vis[i] = 1;
			op_ret[k] = op[i];
			tmp = op[i];
			bt(k+1);
			vis[i] = 0;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op_cnt[i];
	}

	set_op();
	bt(0);
	
	int size = cal_ret.size();
	sort(cal_ret.begin(), cal_ret.end());

	cout << cal_ret[size-1] << '\n';
	cout << cal_ret[0] << '\n';

}
