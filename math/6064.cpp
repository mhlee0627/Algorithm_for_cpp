#include <bits/stdc++.h>
using namespace std;

int t;
int m, n, x, y;
int ans;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b) * b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> x >> y;

        vector<int> vec;
        bool find = 0;
        int lcmv = lcm(n, m);

        for (int i = 0; i <= lcmv; i++) {
            int cur = m*i + x;
            if (cur > lcmv) break;
            vec.push_back(cur);
        }

        for (auto elem : vec) {
            // cout << "elem : " << elem << '\n';
            // cout << "%n: " << elem%n << '\n';

            if (n == y) y = 0;

            if (elem%n == y) {
                cout << elem << '\n';
                find = 1;
                break;
            }
        }

        if (!find) {
            cout << -1 << '\n';
            find = 0;
        }
    }
}
