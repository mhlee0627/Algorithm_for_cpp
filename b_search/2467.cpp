#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans1 = 1e9+1;
	int ans2 = 1e9+1;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr, arr+n, -arr[i]) - arr;

		if (idx+1 < n && i != idx+1 
		
	}
}
