#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> meet[100005];
// first : end time
// second : start time

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> meet[i].second >> meet[i].first;
	}

	sort(meet, meet+n);

	//cout << '\n';
	//for (int i = 0; i < n; i++) {
	//	cout <<  meet[i].second << ' ' << meet[i].first << '\n';
	//}
	//cout << '\n';

	int cnt = 1;
	pair<int, int> cur_meet = {meet[0].first, meet[0].second};

	for (int i = 1; i < n; i++) {
		if (cur_meet.first <= meet[i].second) {
			cur_meet = {meet[i].first, meet[i].second};
			cnt++;
			//cout << "i: " << i << '\n';
			//cout << "meet: " << meet[i].second << '\n';
		}
	}

	cout << cnt << '\n';
}
