#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10005];
int part_sum[10005];
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cur += arr[i];
		part_sum[i+1] = cur;
	}
	
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en <= n && part_sum[en] - part_sum[st] < m) en++;
		if (en == n+1) break;
		if (m == (part_sum[en]-part_sum[st])) cnt++;
	}

	cout << cnt << '\n';
}
