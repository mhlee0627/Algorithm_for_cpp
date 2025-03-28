#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2005];
vector<int> sum_vec;
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j < n; j++) {
            sum_vec.push_back(arr[i] + arr[j]);
        }
    }

    sort(sum_vec.begin(), sum_vec.end());

    for (int i = 0; i < n; i++) {
        if (binary_search(sum_vec.begin(), sum_vec.end(), arr[i])) {
            int st = 0;
            int en = n-1;
            int sum = 0;
            while (st < en) {
                sum = arr[st] + arr[en];
                if (sum > arr[i]) {
                    en--;
                }
                else if (sum < arr[i]) {
                    st++;
                }
                else {
                    if (st != i && en != i) {
                        cnt++;
                        break;
                    }
                    else if (st == i) {
                        st++;
                    }
                    else if (en == i) {
                        en--;
                    }
                    else {
                        st++;
                        en--;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
}