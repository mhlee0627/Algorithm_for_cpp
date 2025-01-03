#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> vec;
unordered_map<string, int> umap;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string temp;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
        umap[temp] = i+1;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp[0] > '9') {
            cout << umap[temp] << "\n";
        }
        else {
            cout << vec[stoi(temp)-1] << "\n";
        }
    }
}
