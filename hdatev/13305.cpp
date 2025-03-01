#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dist;
vector<int> oil;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int tmp;
	for (int i = 0; i < n-1; i++) {
		cin >> tmp;
		dist.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		oil.push_back(tmp);
	}

	long long cost = 0;
	int cur_cost = 0;
	int min_cost = 1000000005;
	for (int i = 0; i < n-1; i++) {
		cur_cost = oil[i];
		min_cost = min(min_cost, cur_cost);
		cost += ((long long)min_cost * (long long)dist[i]);
	}

	cout << cost << '\n';
}
