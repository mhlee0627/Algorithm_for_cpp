#include <bits/stdc++.h>
using namespace std;

int n, m;
// int arr[10];
vector<int> vec(10);
bool vis[10];
int ret[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && tmp != vec[i]) {
            ret[k] = vec[i];
            tmp = vec[i];
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
        cin >> vec[i];

    sort(vec.begin(), vec.begin()+n);

    func(0);
}