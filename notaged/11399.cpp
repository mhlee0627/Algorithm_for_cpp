#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;
vector<int> sum_vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        sum_vec.push_back(sum);
        // cout << i << ": " << sum << "\n";
    }

    int total = 0;
    for (auto elem : sum_vec) {
        total += elem;
    }

    cout << total;
}