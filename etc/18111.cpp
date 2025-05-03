#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int in;
int h_arr[260];

int get_time_work(int h, int b) {
    int ret_time = 0;
    for (int i = 0; i <= 256; i++) {
        if (i > h) {
            ret_time += (h_arr[i] * 2);
        }
        else if (i < h) {
            int gap = h - i;
            if (b == gap) {
                ret_time += gap;
            }
            else if (b < gap) {
                ret_time += b;
                b = 0;
            }
            else {
                ret_time += gap;
                b -= gap;
            }
        }
    }

    return ret_time;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in;
            h_arr[in]++;
        }
    }

    vector<pair<int, int>> vec;
    for (int i = 0; i <= 256; i++) {
        int t = get_time_work(i, b);
        vec.push_back({t, i});
        cout << t << ", " << i << '\n';
    }

    sort(vec.begin(), vec.end());

    cout << vec[0].second << ' ' << vec[0].first << '\n';
}