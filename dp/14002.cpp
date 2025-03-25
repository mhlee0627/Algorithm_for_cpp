#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
pair<int, int> d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    d[1] = {1, 0};
    for (int i = 2; i <= n; i++) {
        pair<int, int> max_d = {0, 0};
        for (int j = i-1; j >= 1; j--) {
            if (arr[j] < arr[i]) {
                max_d = max(max_d, {d[j].first, j});
            }
        }
        d[i] = {max_d.first + 1, max_d.second};
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << d[i].first << " | " << d[i].second << '\n';
    // }

    pair<int, int> max_v = {0, 0};
    for (int i = 1; i <= n; i++) {
        max_v = max(max_v, {d[i].first, i});
    }
    cout << max_v.first << '\n';

    int idx = max_v.second;
    vector<int> vec;
    while (idx) {
        vec.push_back(arr[idx]);
        idx = d[idx].second;
    }

    sort(vec.begin(), vec.end());
    for (auto elem : vec) {
        cout << elem << ' ';
    }
    cout << '\n';
}