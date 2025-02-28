#include <bits/stdc++.h>
using namespace std;

long long s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int i = 0;

    while (s > 0) {
        i++;
        s = s - i;
    }        

    if (s < 0) i--;

    cout << i << '\n';
}