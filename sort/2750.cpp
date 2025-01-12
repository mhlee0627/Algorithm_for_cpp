#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int val = 0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    sort(vec.begin(), vec.end());

    for (const auto& elem : vec) {
        cout << elem << "\n";
    }
}