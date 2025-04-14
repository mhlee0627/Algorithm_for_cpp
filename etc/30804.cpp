#include <bits/stdc++.h>
using namespace std;

int n, type;
int pre[15];
queue<int> q;
int max_v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        int fruit;
        cin >> fruit;
        q.push(fruit);

        if (pre[fruit] == 0) ++type;
        pre[fruit]++;

        while (type > 2) {
            fruit = q.front();
            q.pop();

            pre[fruit]--;
            if (pre[fruit] == 0) --type;

        }

        max_v = max(max_v, static_cast<int>(q.size()));
    }

    cout << max_v << '\n';
}
