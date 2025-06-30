#include <bits/stdc++.h>
using namespace std;

int n;
string board[105];

int rfunc(int r) {
    int ret = 0;
    int len = 0;

    for (int i = 0; i < n; i++) {
        if (board[r][i] == '.') {
            len++;
        }
        else {
            if (len >= 2) ret++;
            
            len = 0;
        }
    }

    if (len >= 2) ret++;

    return ret;
}

int cfunc(int c) {
    int ret = 0;
    int len = 0;

    for (int i = 0; i < n; i++) {
        if (board[i][c] == '.') {
            len++;
        }
        else {
            if (len >= 2) ret++;

            len = 0;
        }
    }

    if (len >= 2) ret++;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    int r = 0;
    int c = 0;

    for (int i = 0; i < n; i++) {
        r += rfunc(i);
        c += cfunc(i);
    }

    cout << r << " " << c << '\n';
}
