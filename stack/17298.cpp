#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000005];
stack<int> s;
stack<int> ret;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int in = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = n; i > 0; i--) {
        while (!s.empty()) {
            if (arr[i] < s.top()) {
                ret.push(s.top());
                s.push(arr[i]);
                break;
            }
            else {
                s.pop();
                continue;
            }
        }

        if (s.empty()) {
            ret.push(-1);
            s.push(arr[i]);
        }
    }

    while (!ret.empty()) {
        cout << ret.top() << ' ';
        ret.pop();
    }
    cout << '\n';
}