#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int susi[33005];
set<int> sset;
int cnt_susi[3005];
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> susi[i];
	}

	for (int i = 0; i < k; i++) {
		susi[n+i] = susi[i];
	}
	
	int ssize = n+k;
	int en = 0;
	for (int st = 0; st < ssize; st++) {
		while (en < ssize && (en-st+1) <= k) {
			cnt_susi[susi[en]]++;
			sset.insert(susi[en]);
			en++;
		}
		if (en == ssize) break;
		if (en-st == k) {
			//cout << "en: " << en << " | st: " << st << '\n';
			//cout << "susi: ";
			sset.insert(c);
			int cursize = sset.size();
			//cout << " | cursize: " << cursize << '\n';
			cnt = max(cnt, cursize);
			
			cnt_susi[susi[st]]--;
			if (cnt_susi[susi[st]] == 0) sset.erase(susi[st]);
		}
	}

	cout << cnt << '\n';
}
