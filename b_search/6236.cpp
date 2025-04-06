#include <bits/stdc++.h>
using namespace std;

int n, m;
int mon[100005];
int min_v = 0x7fffffff;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mon[i];

    int st = 1;
    int en = n*10000;
    bool pass = false;
    
    while (st <= en) {
        int mid = (st+en)/2;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mon[i] > sum) {
                cnt++;
                sum = (mid - mon[i]);
                if (sum < 0) {
                    pass = true;
                    break;
                }
            }
            else {
                sum -= mon[i];
            }
        }

        if (pass || cnt > m) {
            st = mid+1;
            pass = false;
        }
        else {
            min_v = min(min_v, mid);
            en = mid-1;
        }
    }

    cout << min_v << '\n';

}