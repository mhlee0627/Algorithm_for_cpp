#include <bits/stdc++.h>
using namespace std;

#define SK 0
#define CY 1

int n;
bool d[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = SK;
    d[2] = CY;
    d[3] = SK;
    for (int i = 4; i <= n; i++) {
        d[i] = !d[i-3];
    }

    if (d[n] == 0) cout << "SK";
    else cout << "CY";
}