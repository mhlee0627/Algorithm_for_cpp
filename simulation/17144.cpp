#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int r, c, t;
int board[55][55];
queue<int> board_que[55][55];
vector<pair<int, int>> machine_pos;

void print_brd() {
    cout << "print board\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void action1() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] > 0) {
                int grow_cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dirX[dir];
                    int ny = j + dirY[dir];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (board[nx][ny] == -1) continue;
                    
                    grow_cnt++;
                    board_que[nx][ny].push(board[i][j]/5);
                }
                board_que[i][j].push(board[i][j] - (board[i][j]/5)*grow_cnt);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == -1) continue;
            
            int sum = 0;
            while (!board_que[i][j].empty()) {
                sum += board_que[i][j].front();
                board_que[i][j].pop();
            }

            board[i][j] = sum;
        }
    }
}

void action2_high() {
    pair<int, int> high_pos = machine_pos[0];
    
    //좌상 -> 좌하
    for (int i = high_pos.X - 1; i > 0; i--) {
        board[i][0] = board[i-1][0];
    }

    // 우상 -> 좌상
    for (int i = 0; i < c - 1; i++) {
        board[0][i] = board[0][i+1];
    }

    // 우하 -> 우상
    for (int i = 0; i < high_pos.X; i++) {
        board[i][c-1] = board[i+1][c-1];
    }

    // 좌하 -> 우하
    for (int i = c - 1; i > 1; i--) {
        board[high_pos.X][i] = board[high_pos.X][i-1];
    }

    board[high_pos.X][1] = 0;
}

void action2_low() {
    pair<int, int> low_pos = machine_pos[1];

    // 좌하 -> 좌상
    for (int i = low_pos.X + 1; i < r - 1; i++) {
        board[i][0] = board[i+1][0];
    }

    // 우하 -> 좌하
    for (int i = 0; i < c-1; i++) {
        board[r-1][i] = board[r-1][i+1];
    }

    // 우상 -> 우하
    for (int i = r-1; i > low_pos.X; i--) {
        board[i][c-1] = board[i-1][c-1];
    }

    // 좌상 -> 우상
    for (int i = c-1; i > 1; i--) {
        board[low_pos.X][i] = board[low_pos.X][i-1];
    }

    board[low_pos.X][1] = 0;
}

int getSum() {
    int sum = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] > 0) sum += board[i][j];
        }
    }

    return sum;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                machine_pos.push_back({i, j});
            }
        }
    }

    while (t--) {
        action1();
        action2_high();
        action2_low();
    }

    cout << getSum() << '\n';
}