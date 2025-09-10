#include <bits/stdc++.h>
using namespace std;

int n;
int box[1005];
int d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box[i];
        d[i] = 1;
    }
    
    for (int i = 2; i <=n; i++) {
        for (int j = 1; j < i; j++) {
            if (box[j] < box[i]) {
                d[i] = max(d[i], d[j]+1);
            }
        }
    }

    sort(d, d+n+1, greater<int>());

    cout << d[0] << '\n';
}