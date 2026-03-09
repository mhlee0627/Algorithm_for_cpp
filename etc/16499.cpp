#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int, string>> s;

string func(string &str) {
    string ret;
    vector<char> vec;

    for (auto elem : str) {
        vec.push_back(elem);
    }

    sort(vec.begin(), vec.end());

    for (auto elem : vec) {
        ret += elem;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int size = str.size();
        string tstr = func(str);

        s.insert({size, tstr});
    }

    cout << s.size() << '\n';
}