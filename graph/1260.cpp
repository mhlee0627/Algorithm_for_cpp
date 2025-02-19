#include <bits/stdc++.h>
using namespace std;

int n, m, v, s, e;
vector<int> vec[1005];
bool vis[1005];
queue<int> q;
stack<int> st;

void bfs() {
    q.push(v);
    vis[v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto nxt : vec[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    
    cout << '\n';
}

void dfs() {
    st.push(v);
    vis[v] = true;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        cout << cur << " ";
        for (auto nxt : vec[cur]) {
            if (vis[nxt]) continue;
            st.push(nxt);
            vis[nxt] = true;
        }
    }

    cout << '\n';
}

void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : vec[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    } 
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    while (m--) {
        cin >> s >> e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(v);
    cout << '\n';
    for (int i = 0; i < 1005; i++) vis[i] = 0;
    bfs();
}