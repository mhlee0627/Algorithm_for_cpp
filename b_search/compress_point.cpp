#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000005];
int ori[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ori[i] = arr[i];
	}

	sort(arr, arr+n);

	for (int i = 0; i < n; i++) {
		cout << lower_bound(arr, arr+n, ori[i]) - arr << '\n';
	}
}
