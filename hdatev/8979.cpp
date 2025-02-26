#include <bits/stdc++.h>
using namespace std;

int n, k;
tuple<int, int, int, int> ct[1005];

bool cmp(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
	if (get<0>(a) == get<0>(b)) {
		if (get<1>(a) == get<1>(b)) {
			return get<2>(a) > get<2>(b);
		}
		else {
			return get<1>(a) > get<1>(b);
		}
	}

	return get<0>(a) > get<0>(b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int m, g, s, c;
	for (int i = 0; i < n; i++) {
		cin >> m >> g >> s >> c;
		ct[i] = {g, s, c, m};
	}

	sort(ct, ct+n, cmp);

	int grade[1005];
	int res = 0;

	for (int i = 0; i < n; i++) {
		res = 1;
		for (int j = 0; j < i; j++) {
			if (((get<0>(ct[j]) == get<0>(ct[i])) && (get<1>(ct[j]) == get<1>(ct[i]))
				&& (get<2>(ct[j]) == get<2>(ct[i])))) {
				continue;
			}

			res++;
		}
		grade[i] = res;
	}

	for (int i = 0; i < n; i++) {
		if (get<3>(ct[i]) == k) {
			cout << grade[i] << '\n';
			break;
		}
	}
	




}
