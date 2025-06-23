#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ret = 0;
	int st = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > st) {
			ret = max(ret, arr[i] - st);
		}	
		else {
			st = arr[i];	
		}
	}

	cout << ret << '\n';
}
