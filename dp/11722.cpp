#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int max_len = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i]) {
				max_len = max(max_len, dp[j]);
			}
		}
		
		dp[i] = 1 + max_len;
	}

	sort(dp, dp+n+1);

	cout << dp[n] << '\n';
}
