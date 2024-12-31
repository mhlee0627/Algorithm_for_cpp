#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int arr[1000000];
vector<pair<int, int>> vec_oder;
vector<pair<int, int>> vec_ret;
int oder;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec_oder.push_back({x, i});
    }

    sort(vec_oder.begin(), vec_oder.end());

    // for (auto elem : vec_oder) {
    //     cout << "vec_oder: " << elem.first << ", " << elem.second << "\n";
    // }

    vec_ret.push_back({vec_oder[0].second, oder});
    for (int i = 1; i < n; i++) {
        if (vec_oder[i].first != vec_oder[i-1].first) {
            vec_ret.push_back({vec_oder[i].second, ++oder});
        }
        else {
            vec_ret.push_back({vec_oder[i].second, oder});
        }
    }

    sort(vec_ret.begin(), vec_ret.end());

    for (auto elem : vec_ret) {
        cout << elem.second << " ";
        // cout << "vec_ret: " << elem.first << ", " << elem.second << "\n";
    }

}
