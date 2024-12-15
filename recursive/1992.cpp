#include <bits/stdc++.h>
using namespace std;

string board[64];
int N;

void func(int x, int y, int size) {
    bool exit = false;
    for (int n = x; n < x + size; n++) {
        for (int m = y; m < y + size; m++) {
            if (board[n][m] != board[x][y]) {
                exit = true;
                break;
            }
        }
        if (exit) break;
    }

    if (exit) {
        cout << "(";

        int next_size = size / 2;
        func(x, y, next_size);
        func(x, y + next_size, next_size);
        func(x + next_size, y, next_size);
        func(x + next_size, y + next_size, next_size);

        cout << ")";
    } else {
        if (board[x][y] == '0') {
            cout << "0";
        } else {
            cout << "1";
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    func(0, 0, N);
}

