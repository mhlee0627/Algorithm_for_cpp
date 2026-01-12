#include <bits/stdc++.h>
using namespace std;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        unordered_map<int, int> m;
        int n;
        long long s;
        pair<int, long long> maxv = {0, 0};
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s;

            if (m.find(s) != m.end()) {
                m[s] += 1;
                
                if (m[s] > maxv.first) {
                    maxv = {m[s], s};
                }

            }
            else {
                m[s] = 1;
            }
        }

        int ref = n / 2;

        if (maxv.first > ref) {
            cout << maxv.second << '\n';
        }
        else {
            cout << "SYJKGW\n";
        }
    }
}