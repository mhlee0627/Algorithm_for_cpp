#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[105];
int dist[105];
int cnt;

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for (auto nxt : vec[cur]) {
            if (dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int s = 0;
    int e = 0;
    while (m--) {
        cin >> s >> e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }

    for (int i = 0; i < 105; i++) dist[i] = -1;

    bfs();

    cout << cnt-1 << '\n';
}