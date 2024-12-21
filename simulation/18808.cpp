#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int board[40][40];
vector<pair<int, int>> sticker[100];
pair<int, int> sticker_rc[100];
int temp;

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
    // 90
    if (angle == 1) {
        for (auto& elem : sticker[sticker_num]) {
            swap(elem.first, elem.second);
            elem.second = (sticker_rc[sticker_num].first - 1) - elem.second;
        }
    }
    // 180
    else if (angle == 2) {
        for (auto& elem : sticker[sticker_num]) {
            swap(elem.first, elem.second);
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

void right_move(int sticker_num) {
    for (auto& elem : sticker[sticker_num]) {
        elem.second++;
    }
}

void left_move(int sticker_num) {
    for (auto& elem : sticker[sticker_num]) {
        elem.second--;
    }
}

void down_move(int sticker_num) {
    for (auto& elem : sticker[sticker_num]) {
        elem.first++;
    }
}

void up_move(int sticker_num) {
    for (auto& elem : sticker[sticker_num]) {
        elem.first--;
    }
}

bool check_board(int sticker_num) {
    for (auto elem : sticker[sticker_num]) {
        if (elem.first < 0 || elem.first >= n || elem.second < 0 || elem.second >= m) return 0;
        if (board[elem.first][elem.second] == 1) return 0;
    }
    
    for (auto elem : sticker[sticker_num]) {
        board[elem.first][elem.second] = 1;
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

    int move_x = 0;
    int move_y = 0;
    bool success = 0;

    for (int dir = 0; dir < 4; dir++) {
        rotate_sticker(0, dir);
        for (move_x = 0; move_x < m; move_x++) {
            if (check_board(0)) {
                print_board();
                success = true;
                cout << "success1_x(" << move_x << ")\n";
                break;
            }
            right_move(0);
        }
        if (!success) {
            for (int i = 0; i < move_x; i++)
                left_move(0);
        }
        else {
            success = false;
            cout << "success1\n";
            break;
        }

        for (move_y = 0; move_y < n; move_y++) {
            if (check_board(0)) {
                print_board();
                success = true;
                cout << "success2_y(" << move_y << ")\n";
                break;
            }
            down_move(0);
        }
        if (!success) {
            for (int i = 0; i < move_x; i++)
                up_move(0);
        }
        else {
            success = false;
            cout << "success2\n";
            break;
        }
    }

    cout << "next\n";

    for (int dir = 0; dir < 4; dir++) {
        rotate_sticker(1, dir);
        for (move_x = 0; move_x < m; move_x++) {
            if (check_board(1)) {
                print_board();
                success = true;
                cout << "success1_x,dir(" << move_x << "|" << dir << ")\n";
                print_sticker(1);
                break;
            }
            right_move(1);
        }
        if (!success) {
            for (int i = 0; i < move_x; i++)
                left_move(1);
        }
        else {
            success = false;
            cout << "success1\n";
            break;
        }

        for (move_y = 0; move_y < n; move_y++) {
            if (check_board(1)) {
                print_board();
                success = true;
                cout << "success1_y,dir(" << move_y << "|" << dir << ")\n";
                break;
            }
            down_move(1);
        }
        if (!success) {
            for (int i = 0; i < move_x; i++)
                up_move(1);
        }
        else {
            success = false;
            cout << "success2\n";
            break;
        }
    }
}