#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d[1] = 1;
	d[2] = 0;
	d[3] = 1;
	d[4] = 1;
	for (int i = 5; i <= n; i++) {
		if (!d[i-1] || !d[i-3] || !d[i-4]) d[i] = 1;
		else d[i] = 0;
	}

	if (d[n]) cout << "SK\n";
	else cout << "CY\n";
}

