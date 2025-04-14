#include <bits/stdc++.h>
using namespace std;

int n;
const int mod = 1000000;
int dist[1000005];
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 1000005; i++) dist[i] = -1;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxt = 0;
            if (i == 0) {
                nxt = 0;
            }
            else if (i == 1) {
                nxt = (cur + 1) % mod;
            }
            else if (i == 2) {
                nxt = (cur - 1 + mod) % mod;
            }
            else {
                nxt = (cur*2 >= 500000) ? (cur*2 % mod) : (cur*2);
            }

            // 방문했으면 다음
            if (dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    cout << dist[n] << '\n';
}