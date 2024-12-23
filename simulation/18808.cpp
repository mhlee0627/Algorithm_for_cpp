#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int board[40][40];
vector<pair<int, int>> sticker[100];
pair<int, int> sticker_rc[100];
int temp;

int count_sticker() {
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

void print_board() {
    cout << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_sticker(int i) {
    cout << "sticker[" << i << "]\n";
    for (auto elem : sticker[i]) {
        cout << "(x, y): " << elem.first << ", " << elem.second << "\n";
    }
}

void rotate_sticker(int sticker_num, int angle) {
    if (angle == 0) {
        return;
    }
    // 90
    else if (angle == 1) {
        for (auto& elem : sticker[sticker_num]) {
            swap(elem.first, elem.second);
            elem.second = (sticker_rc[sticker_num].first - 1) - elem.second;
        }
    }
    // 180
    else if (angle == 2) {
        for (auto& elem : sticker[sticker_num]) {
            swap(elem.first, elem.second);
            elem.second = (sticker_rc[sticker_num].second - 1) - elem.second;
        }
    }
    // 270
    else if (angle == 3) {
        for (auto& elem : sticker[sticker_num]) {
            swap(elem.first, elem.second);
            elem.second = (sticker_rc[sticker_num].first - 1) - elem.second;
        }
    }
}

bool check_board(int sticker_num, int x, int y) {
    for (auto elem : sticker[sticker_num]) {
        if ((elem.first + x) < 0 || (elem.first + x) >= n || (elem.second + y) < 0 || (elem.second + y) >= m) return 0;
        if (board[elem.first + x][elem.second + y] == 1) return 0;
    }
    
    for (auto elem : sticker[sticker_num]) {
        board[elem.first + x][elem.second + y] = 1;
    }
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        sticker_rc[i] = {r, c};
        for (int a = 0; a < r; a++) {
            for (int b = 0; b < c; b++) {
                cin >> temp;
                if (temp == 1) sticker[i].push_back({a, b});
            }
        }
    }

    // print_sticker(2);
    // rotate_sticker(2, 1);
    // print_sticker(2);
    // rotate_sticker(2, 2);
    // print_sticker(2);
    // rotate_sticker(2, 3);
    // print_sticker(2);

    int move_x = 0;
    int move_y = 0;
    bool success = 0;

    for (int sticker_num = 0; sticker_num < k; sticker_num++) {
        for (int dir = 0; dir < 4; dir++) {
            rotate_sticker(sticker_num, dir);
            for (move_x = 0; move_x < n; move_x++) {
                for (move_y = 0; move_y < m; move_y++) {
                    if (check_board(sticker_num, move_x, move_y)) {
                        // print_board();
                        success = true;
                        break;
                    }
                }
                if (success) {
                    break;
                }
            }
            if (success) {
                success = false;
                break;
            }
        }
    }

    std::cout << count_sticker();
}