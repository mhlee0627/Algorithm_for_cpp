#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10005];
int s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	cin >> m;
	
	sort(arr, arr+n);

	if (m >= s) {
		cout << arr[n-1] << '\n';
	}
	else {
		int st = 1;
		int en = arr[n-1];
		int k = 0;
		int max_k = 0;
		int sum = 0;

		while (st <= en) {
			k = (st+en)/2;
			for (int i = 0; i < n; i++) {
				if (arr[i] < k) {
					sum += arr[i];
				}
				else {
					sum += k;
				}
			}
		
			if (sum <= m) {
				max_k = max(max_k, k);
				st = k+1;
				sum = 0;
			}
			else {
				en = k-1;
				sum = 0;
			}
		}

		cout << max_k << '\n'; 
	}
}
