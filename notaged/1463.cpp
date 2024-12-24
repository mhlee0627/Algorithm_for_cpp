#include <bits/stdc++.h>
using namespace std;

int n;
int g_cnt = 1000000;

void func(int k, int cnt) {
    if (cnt > g_cnt) return;
    if (k == 1) {
        // cout << "cnt: " << cnt << "\n";
        g_cnt = g_cnt > cnt ? cnt : g_cnt;
        // cout << "gcnt: " << g_cnt << "\n";
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            if (k%3 == 0) {
                cnt++;
                // cout << "k/3: " << k/3 << "| cnt: " << cnt << "\n";
                func(k/3, cnt);
                cnt--;
            }
        }
        else if (i == 1) {
            if (k%2 == 0) {
                cnt++;
                // cout << "k/2: " << k/2 << "| cnt: " << cnt << "\n";
                func(k/2, cnt);
                cnt--;
            }
        }
        else {
            cnt++;
            // cout << "k-1: " << k-1 << "| cnt: " << cnt << "\n";
            func(k-1, cnt);
            cnt--;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(n, 0);

    cout << g_cnt;
}