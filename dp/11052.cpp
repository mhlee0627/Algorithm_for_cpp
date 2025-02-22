#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];
int d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    d[1] = p[1];
    d[2] = max(d[1]+p[1], p[2]);
    for (int i = 3; i <= n; i++) {
        int max_v = p[i];
        for (int j = 1; j < i; j++) {
            max_v = max(d[j]+p[i-j], max_v);
        }
        d[i] = max_v;
    }

    // for (int i = 1; i <= n; i++) cout << d[i] << ' ';

    cout << d[n] << '\n';
}