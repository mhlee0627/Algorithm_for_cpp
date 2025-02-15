#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int board[21][21];
int a[11];
bool isUsed[21];
int sum;
vector<int> sum_vec;

int aa[2];
bool isUsed2[21];

void bt2(int k) {
	if (k == 2) {
		for (int i = 0; i < 2; i++) {
			cout << aa[i] << ' ';
		}
		cout << '\n';

		sum += board[aa[0]-1][aa[1]-1];

		return;
	}

	for (int i = 0; i < m; i++) {
		if (!isUsed2[i]) {
			aa[k] = a[i];
			isUsed2[i] = true;
			bt2(k+1);
			isUsed2[i] = false;
		}
	}
}

void func() {
	//cout << "bt2===\n";
	bt2(0);
	//cout << "sum: " << sum << '\n';
	sum_vec.push_back(sum);
	sum = 0;

	//cout << "===bt2\n";
}

void bt(int r, int k) {
	if (k == m) {
		//for (int i = 0; i < m; i++) {
		//	cout << a[i] << ' ';
		//}
		//cout << '\n';
		
		func();

		return;
	}

	for (int i = r; i <= n; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			a[k] = i;
			bt(i+1, k+1);
			isUsed[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	m = n/2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	bt(1, 0);
	
	int min_val = 2000;

	int size = sum_vec.size()/2;
	if (size%2 != 0) size--;

	for (int i = 0; i < size; i++) {
		int val = abs(sum_vec[i] - sum_vec[size-i-1]);
		//cout << "i: " << i << ", val: " << val << '\n';
		min_val = min(val, min_val);

	}

	cout << min_val << '\n';



}
