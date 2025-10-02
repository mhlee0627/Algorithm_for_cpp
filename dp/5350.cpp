#include <bits/stdc++.h>
using namespace std;

int t, n, w;
int d[25][500];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> w;
        vector<int> wvec;
        wvec.push_back(0);
        vector<int> vvec;
        vvec.push_back(0);

        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            wvec.push_back(a);
            vvec.push_back(b);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (j >= wvec[i]) {
                    d[i][j] = max(d[i-1][j], vvec[i] + d[i-1][j-wvec[i]]);
                }
                else {
                    d[i][j] = d[i-1][j];
                }
            }
        }

        cout << d[n][w] << '\n';
    }
}