#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> m;
string p[2505];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

        m[t] = i;
    }

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

        p[i] = t;
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            
            if (m[p[i]] < m[p[j]]) {
                ret++;
            }
        }
    }

    cout << ret << '/' << n*(n-1) / 2 << '\n';
}