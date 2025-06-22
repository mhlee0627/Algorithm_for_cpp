#include <bits/stdc++.h>
using namespace std;

int n, m;
int pos[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }

    int interval = 0;
    int cur = pos[0];
    for (int i = 1; i < m; i++) {
        interval = max(interval, pos[i] - cur);
        cur = pos[i];
    }
    interval = (interval+1)/2;

    interval = max(interval, pos[0]);
    interval = max(interval, n - pos[m-1]);

    cout << interval << '\n';
}