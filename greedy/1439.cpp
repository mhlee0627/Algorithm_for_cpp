#include <bits/stdc++.h>
using namespace std;

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int len = s.size();
	int cnt = 0;

	char pre = s[0];
	for (int i = 1; i < len; i++) {
		if (pre != s[i]) {
			cnt++;
			pre = s[i];
		}
	}

	if (cnt%2 == 0) {
		cout << cnt/2 << '\n';
	}
	else {
		cout << (cnt+1)/2 << '\n';
	}
}
