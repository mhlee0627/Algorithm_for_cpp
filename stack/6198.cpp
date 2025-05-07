#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
long long cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int in;
    while (n--) {
        cin >> in;

        if (s.empty()) {
            s.push(in);
        }
        else {
            while (!s.empty() && s.top() <= in ) {
                s.pop();
            }

            if (s.empty()) {
                s.push(in);
            }
            else {
                s.push(in);
                cnt += (s.size() - 1);
            }
        }
    }

    cout << cnt << '\n';
}