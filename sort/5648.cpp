#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> vec;

ll convert(ll num) {
    string s = to_string(num);

    reverse(s.begin(), s.end());

    return std::stoll(s);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(convert(tmp));
    }

    sort(vec.begin(), vec.end());

    for (auto elem : vec) {
        cout << elem << "\n";
    }
}