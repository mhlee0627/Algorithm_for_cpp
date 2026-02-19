#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;
int waitsts;
int backst;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int st;
            cin >> st;

            q.push(st);

            int cur = q.size();
            if (cur > waitsts) {
                waitsts = cur;
                backst = q.back();
            }
            else if (cur == waitsts) {
                backst = min(backst, q.back());
            }
            
        }
        else {
            q.pop();
        }
    }

    cout << waitsts << ' ' << backst << '\n';
}