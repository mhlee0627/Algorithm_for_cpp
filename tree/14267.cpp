#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;

vector<int> adj[100005];
int parent[100005];
int score[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) continue;
        adj[parent[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        score[a] += b;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (parent[cur] != -1)
            score[cur] += score[parent[cur]];


        for (auto nxt : adj[cur]) {
            if (parent[nxt] == -1) continue;
            q.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++) cout << score[i] << ' ';
    cout << '\n';
}