#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int stock[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) cin >> stock[j];
		
		int cur = stock[n-1];
		long long ans = 0;
		for (int k = n-1; k > 0; k--) {
			if (cur > stock[k-1]) {
					ans += (cur - stock[k-1]);
			} 
			else {
				cur = stock[k-1];
			}
		}

		cout << ans << '\n';

		for (int j = 0; j < n; j++) stock[j] = 0;
	}
}
