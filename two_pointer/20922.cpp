#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[200005];
int cnt[100005];
int max_cnt;
int max_len;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int en = 0;
	cnt[arr[en]]++;
	for (int st = 0; st < n; st++) {
		while (en+1 != n && cnt[arr[en+1]] < k) {
			en++;
			cnt[arr[en]]++;
		}

		max_len = max(max_len, en-st+1);
		
		cnt[arr[st]]--;
	}

	cout << max_len << '\n';
}
