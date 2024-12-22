#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[15][15];

void print_board() {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void func(int x, int y, int w) {
    // up 
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + w; j++) {
            board[x+w][y] = board[x][y] + w;
        }
    }

    // up and right
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            board[i+w][j+w] += (2*w);
        }
    }

    // no step
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            if (i == j || i > j) continue;
            swap(board[i][j], board[j][i]);
        }
    }
    
    // right
    // for (int i = x; i < w; i++) {
    //     for (int j = y; j < w; j++) {
    //         board[i][j+w] = board[i][j];
    //     }
    // }
    // for (int i = x; i < w; i++) {
    //     for (int j = y; j < w; j++) {
    //         if (j > i) continue;
    //         swap(board[i][j], board[w-i][j]);
    //     }
    // }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    board[0][0] = 1;
    board[1][0] = 2;
    board[1][1] = 3;
    board[0][1] = 4;

    func(0, 0, 2);
    print_board();
}