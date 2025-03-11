#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100005];
int sum[100005];
int len = 0x7fffffff;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cur += arr[i];
		sum[i+1] = cur;
	}

	int en = 0;
	for (int st = 0; st <= n; st++) {
		while (en <= n && sum[en] - sum[st] < s) en++;
		if (en == n+1) break;
		len = min(len, en - st);
	}

	if (len > 100005) cout << "0\n";
	else cout << len << '\n';
}

