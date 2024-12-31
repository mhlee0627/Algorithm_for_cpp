#include <bits/stdc++.h>
using namespace std;

int n;
int arr[13];
int ret[13];
// bool vis[13];

void func(int r, int k) {
    if (k == 6) {
        for (int i = 0; i < k; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = r; i < n; i++) {
        ret[k] = arr[i];
        func(i+1, k+1);
        // if (vis[i] == false) {
        //     ret[k] = arr[i];
        //     vis[i] = true;
        //     func(k+1);
        //     vis[i] = false;
        // }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
        }

        func(0, 0);
        cout << "\n";
    }
}