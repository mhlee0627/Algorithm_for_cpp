#include <bits/stdc++.h>
using namespace std;

int n;
int rope[100005];
int w[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	sort(rope, rope+n, greater<int>());

	int max_val = rope[0];
	for (int i = 1; i < n; i++) {
		if (max_val < (rope[i] * (i+1))) {
			max_val = (rope[i] * (i+1));
		}
	}

	cout << max_val << '\n';
}
