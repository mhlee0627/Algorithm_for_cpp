#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> j_vec;
multiset<int> b_set;
long long sum_v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int mi, vi;
    while (n--) {
        cin >> mi >> vi;
        j_vec.push_back({vi, mi});
    }

    int ci;
    while (k--) {
        cin >> ci;
        b_set.insert(ci);
    }

    sort(j_vec.begin(), j_vec.end(), greater<pair<int, int>>());

    for (auto& elem : j_vec) {
        auto itr = b_set.lower_bound(elem.second);
        if (itr != b_set.end()) {
            b_set.erase(b_set.lower_bound(elem.second));
            sum_v += elem.first;
        }
    }

    cout << sum_v << '\n';
}
