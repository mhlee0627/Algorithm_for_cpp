#include <bits/stdc++.h>
using namespace std;

int N;
int board[2187][2187];
int cnt_m1;
int cnt_0;
int cnt_p1;

void func(int x, int y, int size) {
    bool exit = false;
    for (int m = x; m < x + size; m++) {
        for (int n = y; n < y + size; n++) {
            if (board[m][n] != board[x][y]) {
                exit = true;
                break;
            }
        }
        if (exit) {
            break;
        }
    }

    if (exit == false) {
        if (board[x][y] == -1) cnt_m1++;
        else if (board[x][y] == 0) cnt_0++;
        else cnt_p1++;
    }
    else {
        int next_size = size / 3;
        func(x, y, next_size);
        func(x, y + next_size, next_size);
        func(x, y + (2 * next_size), size / 3);

        func(x + next_size, y, next_size);
        func(x + next_size, y + next_size, next_size);
        func(x + next_size, y + (2 * next_size), size / 3);
        
        func(x + (2 * next_size), y, next_size);
        func(x + (2 * next_size), y + next_size, next_size);
        func(x + (2 * next_size), y + (2 * next_size), size / 3);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func(0, 0, N);

    cout << cnt_m1 << "\n" << cnt_0 << "\n" << cnt_p1;
}
