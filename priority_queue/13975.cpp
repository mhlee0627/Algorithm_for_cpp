#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t, k;
int file;
ll ret;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        while (k--) {
            cin >> file;
            pq.push(file);
        }

        while (pq.size() != 1) {
            ll f1 = pq.top();
            pq.pop();
            ll f2 = pq.top();
            pq.pop();
            ll ff = f1 + f2;
            pq.push(ff);
            ret += ff;
        }

        cout << ret << '\n';
        ret = 0;
    }
}