#include <bits/stdc++.h>
using namespace std;

int n;
int t[1500005];
int p[1500005];
int d[1500005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--) {
		if (t[i] > n-i+1) {
			d[i] = d[i+1];
		}
		else {
			d[i] = max(d[i + 1], p[i] + d[i + t[i]]);
		}
	}

	cout << *max_element(d, d+n+1);
}
