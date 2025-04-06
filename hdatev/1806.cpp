#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100005];
int sum[100005];
int min_len = 0x7fffffff;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = pre + arr[i];
        pre = sum[i];
    }

    // for (int i = 0; i <= n; i++) {
    //     cout << sum[i] << ' ';
    // }
    // cout << '\n';

    int en = 1;
    for (int st = 0; st <= n; st++) {
        while (en <= n && sum[en]-sum[st] < s) en++;
        
    }




    int st = 0;
    int en = 1;
    while (st < en) {
        if (sum[en] - sum[st] >= s) {
            min_len = min(min_len, en-st);

            cout << "minlen: " << min_len << " st:en " << st << ":" << en << '\n';

            st++;
        }
        else {
            en++;
        }
    }

    cout << min_len << '\n';
}