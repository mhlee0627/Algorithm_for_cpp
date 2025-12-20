#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char card[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> card[i];

		deque<char> dq;
		dq.push_back(card[0]);

		for (int i = 1; i < n; i++) {
			if (card[i] <= dq.front()) {
				dq.push_front(card[i]);
			}
			else {
				dq.push_back(card[i]);
			}
		}

		for (auto elem : dq) {
			cout << elem;
		}
		cout << '\n';
	}
}
