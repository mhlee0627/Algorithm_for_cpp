#include <bits/stdc++.h>
using namespace std;

int cnt;
string board[12];
int dist[12][6];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
stack<pair<int, int>> s;
vector<pair<int, int>> delete_block;

void dfs(int x, int y, char color) {
    vector<pair<int, int>> temp_vec;
    s.push({x, y});
    temp_vec.push_back({x, y});
    dist[x][y] = 1;
    while (!s.empty()) {
        pair<int, int> curPos = s.top();
        s.pop();
        for (int i = 0; i < 4 ; i++) {
            int nx = curPos.first + dirX[i];
            int ny = curPos.second + dirY[i];
            if (nx < 0 || nx > 11 || ny < 0 || ny > 5) continue;
            if (board[nx][ny] != color || dist[nx][ny] > -1) continue;
            s.push({nx, ny});
            temp_vec.push_back({nx, ny});
            dist[nx][ny] = dist[curPos.first][curPos.second] + 1;
            break;
        }
    }

    if (temp_vec.size() >= 4) {
        // cout << "4 cnt over\n";
        for (auto elem : temp_vec) {
            delete_block.push_back(elem);
        }
    }
}

void clear_dist() {
    for (int i = 0; i < 12; i++)
    for (int j = 0; j < 6; j++) 
        dist[i][j] = -1;
}

void print_dist() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << setw(2) << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_board() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void apply_delete_block_to_board() {
    for (const auto& elem : delete_block) {
        board[elem.first][elem.second] = 'X';
    }
}

void line_check(int x, int y) {
    for (int i = x; i > -1; i--) {
        if (i == 0) {
            board[0][y] = '.';
        }
        else {
            board[i][y] = board[i-1][y];
        }
    }
}

void line_arrange() {
    bool done = 1;
    bool recheck = 0;
    while (done) {
        for (int i = 11; i > -1; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == 'X') {
                    line_check(i, j);
                    recheck = 1;
                    break;
                }

                if (i == 0 && j == 5) {
                    cout << "done\n";
                    done = 0;
                }
            }
            if (recheck) {
                recheck = 0;
                break;
            }
        }
    }
}

void do_dfs() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (dist[i][j] > -1) continue;
            if (board[i][j] == '.') continue;
            dfs(i, j, board[i][j]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        cin >> board[i];
    }

    clear_dist();
    do_dfs();
    print_dist();

    cout << "delete block: \n";
    for (const auto& elem : delete_block) {
        cout << elem.first << ", " << elem.second << "\n";
    }

    while (delete_block.size() != 0) {
        cnt++;
        apply_delete_block_to_board();
        line_arrange();
        print_board(); 
        delete_block.clear();

        clear_dist();
        do_dfs();
    }

    // apply_delete_block_to_board();
    // print_board();
    // line_arrange();
    // print_board();
    
    cout << "cnt: " << cnt;
}