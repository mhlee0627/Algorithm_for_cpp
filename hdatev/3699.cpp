#include <bits/stdc++.h>
using namespace std;

int t, h, l;
int cb[55];
pair<int, int> order[2505];
int order_size = 0;

int get_time_for_car(int i, int j) {
	int elbe_time = 2 * i * 10;
	int f_len = abs(j - cb[i]);
	int b_len = l - f_len;

	int cb_time = (f_len > b_len ? b_len : f_len) * 5;
	
	cb[i] = j;

	return elbe_time + cb_time;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp = 0;

	cin >> t;
	while (t--) {
		cin >> h >> l;
		for (int i = 0; i < h; i++) {	
			for (int j = 0; j < l; j++) {
				cin >> tmp;
				if (tmp > 0) {
					order[tmp] = {i, j};
					order_size++;
				}
			}
		}
			
		long long sum = 0;
		for (int i = 1; i <= order_size; i++) {
			sum += get_time_for_car(order[i].first, order[i].second);
		}

		cout << sum << '\n';

		order_size = 0;
		for (int i = 0; i < 55; i++) cb[i] = 0;
	}
}
