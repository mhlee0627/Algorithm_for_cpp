#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[20];
bool vis[20];
int ret[20];
int cnt;

int get_sum(int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += ret[i];
    }

    return sum;
}

void func(int k, int m) {
    if (k == m) {
        for (int i = 0; i < k; i++)
                cout << "arr: " << ret[i] << " ";
            cout << "\n";

        if (get_sum(k) == s) {
            cnt++;
            for (int i = 0; i < k; i++)
                cout << "arr: " << ret[i] << " ";
            cout << "\n";
        }
        
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ret[k] = arr[i];
            vis[i] = true;
            func(k+1, m);
            vis[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // for (int i = 1; i < n; i++)
    //     func(0, i);
        func(0, 3);

    cout << cnt;
}