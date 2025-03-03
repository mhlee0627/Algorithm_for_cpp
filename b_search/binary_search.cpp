#include <bits/stdc++.h>
using namespace std;

int a[1000];
vector<int> vec;
int n, m;

int binarysearch(int target) {
	int st = 0;
	int en = n-1;
	while (st <= en) {
		int mid = (st+en)/2;
		if (vec[mid] > target) {
			en = mid-1;
		}
		else if (vec[mid] < target) {
			st = mid+1;
		}
		else return 1;
	}

	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}

    sort(vec.begin(), vec.end());

	cin >> m;
	while (m--) {
		cin >> tmp;
		cout << binarysearch(tmp) << '\n';
	}

}
