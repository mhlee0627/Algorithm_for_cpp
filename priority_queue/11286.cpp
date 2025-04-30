#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        
        if (in < 0) {
            pq.push({abs(in), 0});
        }
        else if (in > 0) {
            pq.push({in, 1});
        }
        else {
            if (!pq.empty()) {
                if (!pq.top().second) cout << pq.top().first * -1 << '\n';
                else cout << pq.top().first << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
}