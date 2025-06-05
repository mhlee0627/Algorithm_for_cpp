#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[105];
int dist[105];
map<int, int> lm;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < (n + m); i++) {
        int a, b;
        cin >> a >> b;
        lm[a] = b;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 100) {
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int nxt = cur + i;
            if (nxt < 0 || nxt > 100) continue;
            if (dist[nxt] > 0) continue;
            dist[nxt] = dist[cur] + 1;
            
            if (lm.find(nxt) != lm.end()) {
                int j = lm[nxt];
                if (dist[j] > 0) continue;
                dist[j] = dist[nxt];
                q.push(j);
            }
            else {
                q.push(nxt);
            }
        }
    }

    cout << dist[100] << '\n';
}
