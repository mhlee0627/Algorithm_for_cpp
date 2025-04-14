#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> gr[100005];
int dist[100005];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : gr[cur]) {
            if (dist[nxt] != -1) continue;

            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 100005; i++) dist[i] = -1;

    int s, e;
    for (int i = 0; i < n-1; i++) {
        cin >> s >> e;

        gr[s].push_back(e);
        gr[e].push_back(s);
    }

    bfs(1);

    for (int i = 2; i <= n; i++) {
        int cur_deps = dist[i];

        for (auto chk : gr[i]) {
            if (dist[chk] == cur_deps-1) {
                cout << chk << '\n';
                break;
            }
        }
    }
}
