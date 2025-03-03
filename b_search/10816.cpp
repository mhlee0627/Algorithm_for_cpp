#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int getloweridx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st+en)/2;
		if (vec[mid] >= target) en = mid;
		else st = mid+1;
	}

	return st;
}

int getuperidx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st+en)/2;
		if (vec[mid] > target) en = mid;
		else st = mid+1;
	}

	return st;
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
	
		cout << getuperidx(tmp, n) - getloweridx(tmp, n) << ' ';
	}
	cout << '\n';
}
