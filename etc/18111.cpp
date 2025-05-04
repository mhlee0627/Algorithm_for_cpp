#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int in;
int h_arr[260];

int get_time_work(int h, int b) {
    int ret_time = 0;
    int back = b;
    for (int i = 0; i <= 256; i++) {
        if (h_arr[i] == 0) continue;
        
        if (i > h) {
            ret_time += (h_arr[i] * 2) * (i - h);
            back += h_arr[i] * (i - h);
        }
        else if (i < h) {
            int gap = (h - i) * h_arr[i];
            if (back == gap) {
                ret_time += gap;
                back = 0;
            }
            else if (back < gap) {
                return 0;
            }
            else {
                ret_time += gap;
                back -= gap;
            }
        }
    }

    return ret_time;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
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
        
        if (t != 0)
        {
            vec.push_back({t, i});
            cout << t << ", " << i << '\n';
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    cout << vec[0].first << ' ' << vec[0].second << '\n';
}