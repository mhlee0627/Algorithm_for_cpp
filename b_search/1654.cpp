#include <bits/stdc++.h>
using namespace std;

int k, n;
uint32_t lan[10005];

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	
	uint32_t st = 1;
	uint32_t en = 0;

	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		en = max(en, lan[i]);
	}

	uint32_t x = 0;
	uint32_t max_x = 0;
	
	while (st <= en) {
		int sum = 0;
		x = (st+en)/2;
		for (int i = 0; i < k; i++) {
			sum += (lan[i] / x);
		}

		if (sum >= n) {
			max_x = max(max_x, x);
			st = x+1;
		}
		else {
			en = x-1;
		}
	}

	cout << max_x << '\n';
}
