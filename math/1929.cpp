#include <bits/stdc++.h>
using namespace std;

int n, m;

bool func(int num) {
	if (num == 1) return false;
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (func(i)) cout << i << '\n';
	}
}
