#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
vector<int> sum_vec;
int max_v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum_vec.push_back(arr[i] + arr[j]);
        }
    }

    // for (auto elem : sum_vec) {
    //     cout << elem << ' ';
    // }

    sort(sum_vec.begin(), sum_vec.end());

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (binary_search(sum_vec.begin(), sum_vec.end(), arr[i]-arr[j])) {
                max_v = max(max_v, arr[i]);
            }
        }
    }

    cout << max_v << '\n';
}
