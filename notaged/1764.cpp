#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, bool> umap;
vector<string> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        umap[tmp] = true;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (umap.find(tmp) != umap.end()) {
            cnt++;
            vec.push_back(tmp);
        }
    }

    sort(vec.begin(), vec.end());

    cout << cnt << "\n";
    for (const auto& elem : vec) {
        cout << elem << "\n";
    }
}
