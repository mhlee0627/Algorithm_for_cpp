#include <bits/stdc++.h>
using namespace std;

queue<int> Q;
int dist[100001];
int N, K;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 100001; i++) dist[i] = -1;

    cin >> N >> K;

    Q.push(N);
    dist[N] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < 3; i++)
        {
            int next = 0;
            if (i == 0) next = cur + 1;
            else if (i == 1) next = cur - 1;
            else next = cur * 2;
            if (next < 0 || next > 100000) continue;
            if (dist[next] != -1) continue;

            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }

    cout << dist[K];
}





