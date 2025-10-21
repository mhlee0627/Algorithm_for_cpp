#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> dq;
int cmd;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == 3) {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (cmd == 4) {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (cmd == 5) {
            cout << dq.size() << '\n';
        }
        else if (cmd == 6) {
            if (!dq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else if (cmd == 7) {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    } }