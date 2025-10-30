#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string book;
        cin >> book;

        if (m.find(book) != m.end()) {
            m[book] = m[book] + 1;
        }
        else {
            m[book] = 1;
        }
    }

    int maxv = 0;
    string ret;
    for (auto& pair : m) {
        if (maxv < pair.second) {
            ret = pair.first;
            maxv = pair.second;
        }
    }

    cout << ret << '\n';
}