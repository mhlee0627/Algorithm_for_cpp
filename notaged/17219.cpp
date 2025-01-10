#include <bits/stdc++.h>
using namespace std;

int n, m;

unordered_map<string, string> umap;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string key;
    string val;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        umap[key] = val;
    }

    for (int i = 0; i < m; i++) {
        cin >> key;
        cout << umap[key] << "\n";
    }
}
