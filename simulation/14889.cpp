#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];
bool vis[25];
int arr[25];
bool check[25];
int minv = 0x7fffffff;

void initCheck() {
    for (int i = 0; i < 25; i++) check[i] = 0;
}

int cal() {
    vector<int> t1;
    vector<int> t2;
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            t1.push_back(i);
        }
        else {
            t2.push_back(i);
        }
    }

    for (auto i : t1) {
        for (auto j : t1) {
            if (i != j) {
                sum1 += board[i][j];
            }
        }
    }

    for (auto i : t2) {
        for (auto j : t2) {
            if (i != j) {
                sum2 += board[i][j];
            }
        }
    }

    return abs(sum1 - sum2);
}

void func(int k, int x) {
    if (k == n/2) {
        initCheck();
        for (int i = 0; i < k; i++) check[arr[i]] = true;

        minv = min(minv, cal());

        return;
    }

    for (int i = x; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            arr[k] = i;
            func(k+1, i);
            vis[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    func(0, 1);

    cout << minv << '\n';
}