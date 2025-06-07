#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int p[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    p[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (p[nxt] > 0)  continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }
}