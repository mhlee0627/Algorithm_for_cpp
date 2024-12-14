#include <bits/stdc++.h>
using namespace std;

int N, r, c;

int func(int k, int r, int c) {
    if (k == 0) return 0;
    
    if (r < (1<<(k-1)) && c >= (1<<(k-1))) {
        return func(k-1, r, c - (1<<(k-1))) + (1<<(k-1))*(1<<(k-1));
    }
    else if (r >= (1<<(k-1)) && c < (1<<(k-1))) {
        return func(k-1, r - (1<<(k-1)), c) + (2 * (1<<(k-1))*(1<<(k-1)));
    }
    else if (r >= (1<<(k-1)) && c >= (1<<(k-1))) {
        return func(k-1, r - (1<<(k-1)), c - (1<<(k-1))) + (3 * (1<<(k-1))*(1<<(k-1)));
    }
    else {
        return func(k-1, r, c);
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;

    cout << func(N, r, c);
}
