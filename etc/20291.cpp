#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> m;

string findexe(string& in) {
    size_t pos = in.find('.');

    return in.substr(pos + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string in;
        cin >> in;

        string exe = findexe(in);

        if (m.find(exe) !=  m.end()) {
            m[exe]++;
        }
        else {
            m[exe] = 1;
        }
    }

    for (auto elem : m) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}