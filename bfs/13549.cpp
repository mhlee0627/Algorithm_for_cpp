#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000+1

int n, k;
bool vis[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, n});
	vis[n] = 1;

	while (!q.empty()) {
		int t = q.top().first;
		int x = q.top().second;
		q.pop();

		if (x == k) {
			cout << t << '\n';			
			break;
		}

		if (x * 2 < MAX_SIZE && !vis[x * 2]) {
			q.push({t, x * 2});
			vis[x * 2] = 1;
		}
	
		if (x + 1 < MAX_SIZE && !vis[x + 1]) {
			q.push({t + 1, x + 1});
			vis[x + 1] = 1;
		}

		if (x - 1 >= 0 && !vis[x - 1]) {
			q.push({t + 1, x - 1});
			vis[x - 1] = 1;
		}
	}
}
