#include <bits/stdc++.h>
using namespace std;

int n, m;
long long c[1005];

void func() {
	sort(c, c+n);
	long long sum = c[0] + c[1];
	c[0] = sum;
	c[1] = sum;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < m; i++) {
		func();
	}
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += c[i];
	}

	cout << sum << '\n';
}
