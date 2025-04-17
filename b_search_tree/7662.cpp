#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        multiset<long long> ms;
        cin >> k;
        
        while (k--) {
            char cmd;
            cin >> cmd;
            if (cmd == 'I') {
                long long input;
                cin >> input;
                ms.insert(input);
            }
            else {
                long long input;
                cin >> input;
                if (ms.empty()) continue;

                if (input == 1) {
                    ms.erase(prev(ms.end()));
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
}