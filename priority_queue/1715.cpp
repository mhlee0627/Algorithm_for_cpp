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
    while (n--) {
        cin >> in;
        pq.push(in);
    }

    int cur1 = 0;
    int cur2 = 0;
    int sum = 0;
    while (pq.size() != 1) {
        cur1 = pq.top();
        pq.pop();
        cur2 = pq.top();
        pq.pop();

        sum += (cur1 + cur2);
        pq.push(cur1 + cur2);
    }

    cout << sum << '\n';
}