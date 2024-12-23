#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[32768][32768];

void print_board() {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] < 10){
                cout << " ";
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void func(int w) {
    if (w == (n*2)) return;
    // up 
    int halfw = w/2;
    for (int i = 0; i < halfw; i++) {
        for (int j = 0; j < halfw; j++) {
            board[i+halfw][j] = board[i][j] + pow(halfw, 2);
        }
    }

    // up and right
    for (int i = 0; i < halfw; i++) {
        for (int j = 0; j < halfw; j++) {
            board[i+halfw][j+halfw] =  board[i][j] + (2 * pow(halfw, 2));
        }
    }

    // no step
    for (int i = 0; i < halfw; i++) {
        for (int j = 0; j < halfw; j++) {
            if (i == j || i > j) continue;
            swap(board[i][j], board[j][i]);
        }
    }
    
    // right
    for (int i = 0; i < halfw; i++) {
        for (int j = 0; j < halfw; j++) {
            board[i][j+halfw] = board[halfw-1-i][halfw-1-j] + (3 * pow(halfw, 2));
        }
    }

    // cout << "debug: " << w << "\n";
    func((w * 2));
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

    func(2);
    // print_board();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == m) {
                cout << j+1 << " " << i+1;
            }
        }
    }
}