#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> ta[16];
int d[30];
int rtime;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ta[i].first >> ta[i].second;
    }

	rtime = 1;
	int ans = 0;
	for (int j = n; j > 0; j--) {
		if (rtime >= ta[j].first) {
			ans += ta[j].second;
			rtime = rtime - ta[j].first;
		}
		rtime++;
	}

	cout << ans << '\n';
}
