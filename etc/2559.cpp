#include <bits/stdc++.h>
using namespace std;

int n, k;
int sum;
int ret = (-100 * 100001);
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;

        if (q.size() < k) {
            sum += in;
            q.push(in);
        }
        else {
            ret = max(ret, sum);
            // cout << "i: " << i << "| ret: " << ret << '\n';

            sum -= q.front();
            q.pop();

            sum += in;
            q.push(in);
        }
    }

    ret = max(ret, sum);

    cout << ret << '\n';
}