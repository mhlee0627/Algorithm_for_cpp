#include <bits/stdc++.h>
using namespace std;

int n, m;
int tree[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree, tree+n);
	int h = 0;
	int max_h = 0;
	int st = 1;
	int en = tree[n-1];
    long long cut = 0;

	while (st <= en) {
		h = (st+en)/2;
		for (int i = 0; i < n; i++) {
			if (tree[i] > h) {
				cut += (tree[i] - h);
			}
		}
		
		if (cut >= m) {
			max_h = max(max_h, h);
			st = h+1;
			cut = 0;
		}
		else {
			en = h-1;
			cut = 0;
		}
	}

	cout << max_h << '\n';
}
