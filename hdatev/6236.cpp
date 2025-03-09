#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int st = 1;
	int en = n*10000;
	int k = 0;
	int min_k = en;
	bool pass = false;

	while (st <= en) {
		int sum = 0;
		int cnt_m = 0;
		k = (st+en)/2;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sum) {
				cnt_m++;
				sum = k;
				sum -= arr[i];
				if (sum < 0) pass = true;
			}
			else {
				sum -= arr[i];
			}
		}

		cout << "k: " << k << " | cnt_m: " << cnt_m;

		if (pass || cnt_m > m) {
			cout << " | 111" << '\n';
			st = k+1;
			pass = false;
		}
		else {
			cout << " | 222" << '\n';
			en = k-1;
			min_k = min(min_k, k);
		}
	}

	cout << min_k << '\n';
}
