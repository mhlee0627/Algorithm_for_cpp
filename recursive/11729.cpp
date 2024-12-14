#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
queue<pair<int, int>> Q;

void func(int k, int src, int dst, int empty) {
    if (k == 1) {
        cnt++;
        Q.push({src, dst});
        // cout << src << " " << dst << "\n";
        return;
    }
    func(k-1, src, empty, dst);
    cnt++;
    // cout << src << " " << dst << "\n";
    Q.push({src, dst});
    func(k-1, empty, dst, src);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    func(N, 1, 3, 2);
    cout << cnt << "\n";
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << cur.first << " " << cur.second << "\n";
    }
}