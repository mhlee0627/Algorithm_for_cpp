#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec[55];
int dist[55];

void dist_clear() {
	for (int i = 0; i < 55; i++) dist[i] = -1;
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	dist[st] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : vec[cur]) {
			if (dist[nxt] >= 0) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int get_max_dist() {
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dist[i]);
	}

	return mx;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int s = 0;
	int e = 0;
	cin >> s >> e;
	while (s != -1 && e != -1) {
		vec[s].push_back(e);
		vec[e].push_back(s);

		cin >> s >> e;
	}

	vector<pair<int, int>> ret;
	for (int i = 1; i <= n; i++) {
		dist_clear();
		bfs(i);
		ret.push_back({get_max_dist(), i});
	}

	sort(ret.begin(), ret.end());

	vector<int> cap;
	cap.push_back(ret[0].second);
	int min_v = ret[0].first;
	for (int i = 1; i < ret.size(); i++) {
		if (ret[i].first > min_v) break;
		cap.push_back(ret[i].second);
	}

	sort(cap.begin(), cap.end());
	cout << min_v << ' ' << cap.size() << '\n';
	for (auto elem : cap) {
		cout << elem << ' ';
	}
	cout << '\n';
}
