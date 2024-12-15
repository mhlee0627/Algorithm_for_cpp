#include <bits/stdc++.h>
using namespace std;

int N;
int cnt_1;
int cnt_0;
int board[1<<7][1<<7];

void func(int x, int y, int size) {
    bool exit = false;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board[i][j] != board[x][y]) {
                exit = true;
                break;
            }
        }
        if (exit) break;
    }

    if (exit) {
        int next_size = size / 2;
        func(x, y, next_size);
        func(x, y + next_size, next_size);
        func(x + next_size, y, next_size);
        func(x + next_size, y + next_size, next_size);
    }
    else {
        if (board[x][y] == 0) cnt_0++;
        else cnt_1++;
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        cin >> board[i][j];

    func(0, 0, N);
    cout << cnt_0 << "\n" << cnt_1;    
}