#include <bits/stdc++.h>
using namespace std;

int N;
char board[3100][3100*2 - 1];

void func(int x, int y, int size) {
    if (size == 3) {
        for (int i = x; i > (x - size); i--) {
            for (int j = y; j < y + (size*2 -1); j++) {
                if (i == x) board[i][j] = '*';
                else if (i == (x-2) && j == (y+2)) board[i][j] = '*';
                else if (i == (x-1) && (j == (y+1) || j == (y+3))) board[i][j] = '*';
                else
                    continue;
            }
        }
        return;
    } else {
        int next_size = size / 2;
        func(x, y, next_size);
        func(x - next_size, y + next_size, next_size);
        func(x, y + size, next_size);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3100; i++)
    for (int j = 0; j < (3100*2 - 1); j++)
        board[i][j] = ' ';

    cin >> N;
    
    func(N-1, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N*2 - 1); j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

}