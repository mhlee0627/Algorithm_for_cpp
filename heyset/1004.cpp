#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n;
pair<int, int> s;
pair<int, int> e;
vector<tuple<int, int, int>> p;
int cnt;
bool ss;
bool ee;

void func() {
	for (auto& elem : p) {
		int tx = get<0>(elem);
		int ty = get<1>(elem);
		int tr = get<2>(elem);

		if (((s.X-tx)*(s.X-tx) + (s.Y-ty)*(s.Y-ty)) < tr*tr) ss = 1;
		if (((e.X-tx)*(e.X-tx) + (e.Y-ty)*(e.Y-ty)) < tr*tr) ee = 1;

		if (ss == 1 && ee == 0) cnt++;
		if (ss == 0 && ee == 1) cnt++;

		ss = 0;
		ee = 0;
	}

	cout << cnt << '\n';
	cnt = 0;
	p.clear();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	int tx, ty = 0;
	for (int T = 0; T < t; T++) {
		cin >> tx >> ty;
		s = {tx, ty};
		cin >> tx >> ty;
		e = {tx, ty};

		cin >> n;
		int px, py, pr = 0;
		for (int i = 0; i < n; i++) {
			cin >> px >> py >> pr;
			p.push_back({px, py, pr});
		}

		func();
	}
}





