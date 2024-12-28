#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    vector<char> result;
    int cnt = 1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (cnt <= x) {
            s.push(cnt);
            cnt++;
            result.push_back('+');
        }

        if (s.top() == x) {
            s.pop();
            result.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (auto elem : result) {
        cout << elem << "\n";
    }
}