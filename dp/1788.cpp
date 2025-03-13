#include <bits/stdc++.h>
using namespace std;

int n;
bool minusv;
unsigned long long d[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;  
    if (n < 0) {
        minusv = true;
        n = (n * -1);
    }
    
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1]%1000000000 + d[i-2]%1000000000;
    }

    if (n == 0) {
        cout << "0\n0\n";
    }
    else if (!minusv) {
        cout << "1\n" << d[n]%1000000000 << '\n';
    }
    else {
        if (n%2 == 0) {
            cout << "-1\n" << d[n]%1000000000 << '\n';
        }
        else {
             cout << "1\n" << d[n]%1000000000 << '\n';
        }
    }
}