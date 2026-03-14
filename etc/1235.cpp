#include <bits/stdc++.h>
using namespace std;

int n;
int size;
vector<string> vec;

bool func(int t) {
    set<string> s;

    for (auto elem : vec) {
        string str = elem.substr(size - t, t);

        if (s.find(str) == s.end()) {
            s.insert(str);
            continue;
        }
        return false;
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    size = vec[0].size();

    for (int i = 1; i <= size; i++) {
        if (func(i)) {
            cout << i << '\n';
            return 0;
        }
    }
}