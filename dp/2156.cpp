#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10005];
int d[10005];

int main(void)
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];

        d[1] = arr[1];
        d[2] = arr[1] + arr[2];
        for (int i = 3; i <= n; i++) {

                d[i] = max({(d[i-3] + arr[i-1] + arr[i]), (d[i-2] + arr[i]), d[i-1]});
        }

        cout << d[n] << '\n';
}
