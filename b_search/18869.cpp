#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> planit[105];
vector<int> origin[105];
vector<int> compre[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	int tmp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			planit[i].push_back(tmp);
			origin[i].push_back(tmp);
		}
	}

	for (int i = 0; i < m; i++) {
		sort(planit[i].begin(), planit[i].end());	
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		compre[i].push_back(lower_bound(planit[i].begin(), planit[i].end(), origin[i][j]) - planit[i].begin());
			
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			if (compre[i] == compre[j]) cnt++;
		}
	}

	cout << cnt << '\n';
}
