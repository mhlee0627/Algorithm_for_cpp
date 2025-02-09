#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;
int s;
int e;
long long ret;

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << vec[i].first << ", " << vec[i].second << '\n';
	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int in1, in2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> in1 >> in2;
		vec.push_back({in1, in2});
	}

	sort(vec.begin(), vec.end());

	//print();

	s = vec[0].first;
	e = vec[0].second;
	if (n == 1) {
		ret = e - s;
	}

	for (int i = 1; i < n; i++) {
		if (e >= vec[i].first) {
			if (e < vec[i].second) e = vec[i].second;
		} 
		else {
			ret += (e - s);
			s = vec[i].first;
			e = vec[i].second;
		}

		if (i == n-1) {
			ret += (e - s);
		}
	}

	cout << ret << '\n';
}
