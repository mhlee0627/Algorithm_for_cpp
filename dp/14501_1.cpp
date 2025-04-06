#include <bits/stdc++.h>
using namespace std;

int n;
int w_time[20];
int pay[20];
int d[20];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w_time[i] >> pay[i];

    for (int i = n; i >= 1; i--) {
        if (n+1-i-w_time[i] < 0) {
            d[i] = d[i+1];
        }
        else {
            d[i] = max(d[i+w_time[i]] + pay[i], d[i+1]);
        }
    }

    cout << *max_element(d, d+n+1) << '\n';
}