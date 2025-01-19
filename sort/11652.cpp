#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll arr[100001];
int cnt;
ll mxval = -(1ll << 62) - 1;
int mxcnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxval = arr[i-1];
            }
            cnt = 1;
            break;
        }

        if (arr[i-1] == arr[i]) {
            cnt++;
        }
        else {
            if (cnt > mxcnt) {
                mxcnt = cnt;
                mxval = arr[i-1];
            }
            cnt = 1;
        }
    }

    cout << mxval;
}