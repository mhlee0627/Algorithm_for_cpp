#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> ta[16];
int d[30];
int pre[30];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ta[i].first >> ta[i].second;
    }

	d[1] = 0;
	d[1 + ta[1].first] = ta[1].second;
	for (int i = (1+ta[1].first); i <= n+5; i++) {
		d[i] = ta[1].second;
	}


	for (int i = 2; i <= n; i++) {
		if ((d[i] + ta[i].second) > d[i + ta[i].first]) {
			//d[i + ta[i].first] = d[i] + ta[i].second;
			for (int j = (i+ta[i].first); j <= n+5; j++)
				d[j] = d[i] + ta[i].second;
		}
	}

	for (int i = 1; i <= n+1; i++) {
		cout << i << ": " << d[i] << '\n';
	}
	

	int max = 0;
	for (int i = 1; i <= n+1; i++) {
		if (d[i] > max) max = d[i];
	}
	cout << max << '\n';	
}
