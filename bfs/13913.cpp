#include <bits/stdc++.h>
using namespace std;

int n, k;
// int dist[100005];
pair<int, int> dist[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < 100005; i++) {
        dist[i].first = -1;
        dist[i].second = -1;
    }

    queue<int> q;
    q.push(n);
    dist[n].first = 0;
    dist[n].second = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) {
            break;
        }

        for (int i = 0; i <3; i++) {
            int nn = 0;
            if (i == 0) {
                nn = cur * 2;
            }
            else if (i == 1) {
                nn = cur + 1;
            }
            else {
                nn = cur - 1;
            }

            if (nn < 0 || nn > 100000) continue;
            if (dist[nn].first >= 0) continue;

            q.push(nn);
            dist[nn].first = dist[cur].first + 1;
            dist[nn].second = cur;
        }
    }

    stack<int> s;

    int pre = k;
    while (1) {
        if (pre == -1) break;

        s.push(pre);
        pre = dist[pre].second;
    }

    cout << dist[k].first << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}
