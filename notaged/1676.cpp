#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 5; i <= n; i *= 5) {
        cnt += (n/i);
    }

    cout << cnt;
}