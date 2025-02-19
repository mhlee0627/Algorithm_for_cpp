#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[1005];
int d[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int max_v = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				max_v = max(max_v, d[j]);
			}
		}
		d[i] = max_v + 1;
	}

	sort(d, d+n+1);

	cout << d[n] << '\n';
}
