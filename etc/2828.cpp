#include <bits/stdc++.h>
using namespace std;

int n, m, j;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> j;

    int st = 1;
    int en = m;
    int ret = 0;

    for (int i = 0; i < j; i++) {
        int ap;
        cin >> ap;

        if (ap > en) {
            int offset = (ap - en);
            ret += offset;
            en += offset;
            st += offset;
        }
        else if (ap < st) {
            int offset = (st - ap);
            ret += offset;
            st -= offset;
            en -= offset;
        }
    }

    cout << ret << '\n';
}