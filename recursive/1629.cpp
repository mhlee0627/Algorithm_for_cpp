#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A, B, C = 0;

ll func(ll n) {
    if (n == 1) return A % C; 
    ll half = func(n / 2);
    half = (half * half) % C;
    if (n % 2 == 1) {
        return (half * A) % C;
    }
    return half;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << func(B);
}

