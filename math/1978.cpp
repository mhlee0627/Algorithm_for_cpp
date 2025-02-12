#include <bits/stdc++.h>
using namespace std;

int n;

bool func(int num) {
	if (num == 1) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int val = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (func(val)) cnt++;
	}

	cout << cnt << '\n';
}
