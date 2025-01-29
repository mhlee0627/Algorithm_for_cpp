#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int d[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    d[1] = arr[1];
    int vmax = d[1];
    for (int i = 2; i <= n; i++) {
        d[i] = max(d[i-1] + arr[i], arr[i]);
        vmax = d[i] > vmax ? d[i] : vmax;
    }

    cout << vmax;
}