#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> avec;
vector<int> bvec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    int tmp;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            avec.push_back(tmp);
        }
        for (int k = 0; k < m; k++) {
            cin >> tmp;
            bvec.push_back(tmp);
        }

        sort(avec.begin(), avec.end(), greater<int>());
        sort(bvec.begin(), bvec.end(), greater<int>());

        int cnt = 0;
        while (avec.size() != 0) {
            if (avec[0] > bvec[0]) {
                cnt += bvec.size();
                avec.erase(avec.begin());
            }
            else {
                bvec.erase(bvec.begin());
                if (bvec.size() == 0) break;
            }
        }
        avec.clear();
        bvec.clear();

        cout << cnt << '\n';
    }
}