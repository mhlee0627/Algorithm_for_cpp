#include <bits/stdc++.h>
using namespace std;

int f, s, g;
int mv[2];
queue<int> q;
int dist[1000005];
bool ret;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> mv[0] >> mv[1];

    for (int i = 0; i <= f; i++) dist[i] = -1;

    if (s == g) {
        cout << 0 << '\n';
        return 0;
    }

    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int next = 0;
            if (i == 0) next = cur + mv[i];
            else next = cur - mv[i];

            if (next <= 0 || next > f) continue;
            if (dist[next] >= 0) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
            if (next == g) ret = true;
        }
    }

    if (ret) cout << dist[g] << '\n';
    else cout << "use the stairs\n";
}