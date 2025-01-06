#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[10];
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(n--) {
        cnt += (k / arr[n]);
        k = (k % arr[n]);
    }

    cout << cnt;
}