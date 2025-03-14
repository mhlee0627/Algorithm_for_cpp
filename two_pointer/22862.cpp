
#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1000005];
int odd_cnt;
int max_len;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> arr[i];

    int en = 0;
    if (arr[en]%2 != 0) odd_cnt++;
    for(int st = 0; st < n; st++) {
        while (en+1 < n && odd_cnt <= k) {
            en++;
            if (arr[en]%2 != 0) odd_cnt++;
        }

        // cout << "st: " << st << ", en:" << en << ", odd_cnt:" << odd_cnt;
        max_len = max(max_len, en-st+1-odd_cnt);
        // cout << ", max_len: " << max_len << '\n';
        if (arr[st]%2 != 0) odd_cnt--;
    }

    cout << max_len << '\n';
}