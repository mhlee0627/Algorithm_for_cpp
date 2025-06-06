#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int in;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> in;

            if (pq.size() >= n) {
                if (in > pq.top()) {
                    pq.pop();
                    pq.push(in);
                }
            }
            else {
                pq.push(in);
            }
        }
    }

    cout << pq.top() << '\n';
}