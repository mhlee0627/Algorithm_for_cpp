#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ab;
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ab.push_back(tmp);
	}

	sort(ab.begin(), ab.end());

	long long t_ab = 0;
	int l_idx = n-1;
	for (int i = 0; i < l_idx; i++) {
		t_ab = (ab[i] + ab[l_idx]);
		if (t_ab >= m) {
			l_idx--;
			cnt++;
		}
	}

	cout << cnt << '\n';
}
