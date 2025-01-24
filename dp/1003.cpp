#include <bits/stdc++.h>
using namespace std;

pair<int, int> d[41];
int t, tmp;

void dp() {
    d[0].first = 1;
    d[0].second = 0;
    d[1].first = 0;
    d[1].second = 1;
    for (int i = 2; i <= tmp; i++) {
        d[i].first = d[i-1].first + d[i-2].first;
        d[i].second = d[i-1].second + d[i-2].second;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        dp();
        cout << d[tmp].first << " " << d[tmp].second << "\n";
    }
}
