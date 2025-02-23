#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> tb;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int m = 0;
	int d = 0;
	while (n--) {
		cin >> m >> d;
		if (m >= d) k--;
		else {
			tb.push_back(d-m);
		}
	}

	if (k <= 0) cout << 0 << '\n';
	else {
		sort(tb.begin(), tb.end());
		cout << tb[k-1] << '\n';
	}

}
