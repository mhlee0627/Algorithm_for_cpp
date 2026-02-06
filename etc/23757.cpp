#include <bits/stdc++.h>
using namespace std;

int n, m;
priority_queue<int> boxs;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		boxs.push(b);
	}
	
	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;

		auto cur = boxs.top();
		if (cur > s) {
			boxs.pop();
			boxs.push(cur-s);
		}
		else if (cur == s) {
			boxs.pop();
		}
		else {
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}
