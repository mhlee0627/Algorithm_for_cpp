#include <bits/stdc++.h>
using namespace std;

int N;
char board[2200][2200];

void zero_set(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            board[i][j] = ' ';
        }
    }
}

void func(int x, int y, int size) {
    if (size == 3) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if ((i == x+(size/2)) && j == y+(size/2)) {
                    board[i][j] = ' ';
                    continue;
                }
                board[i][j] = '*';
            }
        }
        return;
    } else {
        int next_size = size / 3;
        func(x, y, next_size);
        func(x, y + next_size, next_size);
        func(x, y + (2 * next_size), next_size);
    
        func(x + next_size, y, next_size);
        zero_set(x + next_size, y + next_size, next_size);
        func(x + next_size, y + (2 * next_size), next_size);

        func(x + (2 * next_size), y, next_size);
        func(x + (2 * next_size), y + next_size, next_size);
        func(x + (2 * next_size), y + (2 * next_size), next_size);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}