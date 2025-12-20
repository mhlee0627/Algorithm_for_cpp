#include <bits/stdc++.h>
using namespace std;

int t;

int func(vector<int>& rv, int h)
{
    int curlen = rv.size();
    int i = 0;

    for (; i < curlen; i++) {
        if (rv[i] > h) {
            rv.insert(rv.begin() + i, h);
            break;
        }
    }

    if (i == curlen) {
        rv.push_back(h);
        return 0;
    }
    else {
        return curlen - i;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        vector<int> v;
        int start;
        int h;
        int sum = 0;

        cin >> start;
        cin >> h;
        v.push_back(h);

        for (int i = 1; i < 20; i++) {
            cin >> h;

            sum += func(v, h);
        }

        cout << start << ' ' << sum << '\n';
    }

}