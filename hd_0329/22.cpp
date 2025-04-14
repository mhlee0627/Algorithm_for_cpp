#include <bits/stdc++.h>
using namespace std;

int n;

int find_min_steps(int target) {
    const int MOD = 1000000;
    vector<int> dist(MOD, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) return dist[cur];

        for (int i = 0; i < 4; i++) {
            int nxt = 0;
            if (i == 0) {
                nxt = 0;
            }
            else if (i == 1) {
                nxt = (cur + 1) % MOD;
            }
            else if (i == 2) {
                nxt = (cur - 1 + MOD) % MOD;
            }
            else {
                nxt = (cur*2 >= 500000) ? (cur * 2 % MOD) : (cur * 2);
            }

            if (dist[nxt] != -1) continue; // 방문했으면 다음
            
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    return -1; // 도달 불가능
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << find_min_steps(n) << '\n';
}