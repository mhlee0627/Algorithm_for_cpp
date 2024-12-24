#include <bits/stdc++.h>
using namespace std;

int n, m;
int s, e;
int arr[100001];
int sum[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n+1; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        // cout << "sum: " << sum[i] << "\n";
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << sum[e] - sum[s-1] << "\n";
    }
}