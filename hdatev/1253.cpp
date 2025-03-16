#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2005];
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for (int cur = 0; cur < n; cur++) {
        int st = 0;
        int en = n-1;
        
        while (st < en) {
            int sum = arr[st] + arr[en];
            if (sum < arr[cur]) st++;
            else if (sum > arr[cur]) en--;
            else {
                if (st != cur && en != cur) {
                    cnt++;
                    break;
                }
                else if (st == cur) {
                    st++;
                }
                else if (en == cur) {
                    en--;
                }
            }
        }
    }
    
    cout << cnt << '\n';
}