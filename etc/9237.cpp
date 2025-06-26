#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n, greater<int>());

    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, i+2+arr[i]);
    }

    cout << ret << '\n';
}