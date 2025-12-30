#include <bits/stdc++.h>
using namespace std;

int n, m;
set<pair<int, int>> s; // l, p
unordered_map<int, int> um; // p, l

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        s.insert({l, p});
        um[p] = l;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                auto itr = prev(s.end());
                cout << itr->second << '\n';
            }
            else {
                auto itr = s.begin();
                cout << itr->second << '\n';
            }
        }
        else if (cmd == "add") {
            int p, l;
            cin >> p >> l;
            s.insert({l, p});
        }
        else {
            int p;
            cin >> p;
            int l = um[p];

            s.erase({l, p});
        }
    }
}