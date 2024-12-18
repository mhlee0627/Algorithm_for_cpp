#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr(10);
int ret[10];
bool vis[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << ret[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ret[k] = arr[i];
            vis[i] = true;
            func(k+1);
            vis[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    std::sort(arr.begin(), arr.begin() + n);

    func(0);
}