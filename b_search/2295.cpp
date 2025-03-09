#include <bits/stdc++.h>
using namespace std;

int n;
int u[1005];
vector<int> u2;

void set_u2() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			u2.push_back(u[i] + u[j]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u[i];
	}

	sort(u, u+n);

	set_u2();

	sort(u2.begin(), u2.end());

	int cur = 0;
	int max_v = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cur = u[i] - u[j];
			if (cur <= 0) continue;
			if (binary_search(u2.begin(), u2.end(), cur)) {
				max_v = max(max_v, u[i]);
			}
		}
	}

	cout << max_v << '\n';
}
