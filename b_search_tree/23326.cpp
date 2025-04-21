#include <bits/stdc++.h>
using namespace std;

int n, q;
map<int, bool> m;
int pos;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
       
    cin >> n >> q;
    bool input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input) m[i] = true;
    }

    int cmd;
    int x;

    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (m[x-1]) m.erase(x-1);
            else m[x-1] = true;           
        }
        else if (cmd == 2) {
            cin >> x;
            pos = (pos + x) % n;
        }
        else {
            if (m.size() == 0) {
                cout << -1 << '\n';
            }
            else {
                auto itr = m.lower_bound(pos);
                if (itr == m.end()) {
                    int val = (n - pos) + m.begin()->first;
                    cout << val << '\n';
                }
                else {
                    cout << itr->first - pos << '\n';
                }
            }
        }
    }
}
