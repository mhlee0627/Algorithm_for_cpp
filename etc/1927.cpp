#include <bits/stdc++.h>
using namespace std;

int n, x;
multiset<int> ms;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> x;
        
        if (x != 0) {
            ms.insert(x);
        }
        else {
            if (ms.empty()) {
                cout << 0 << '\n';
                continue;
            }

            cout << *ms.begin() << '\n';
            ms.erase(ms.begin());
        }
    }
}