#include <bits/stdc++.h>
using namespace std;

string board[12];
int dist[12][6];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
stack<pair<int, int>> s;
vector<pair<int, int>> delete_block;

void find_delete_block(int x, int y, char color) {
    stack<pair<int, int>> t_s;

}

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
        cout << "4 cnt over\n";
        delete_block = temp_vec;
        for (auto elem : delete_block) {
            cout << elem.first << ", " << elem.second << "\n";
        }

    }
}

void clear_dist() {
    for (int i = 0; i < 12; i++)
    for (int j = 0; j < 6; j++) 
        dist[i][j] = -1;
}

void print() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << setw(2) << dist[i][j] << " ";
        }
        cout << "\n";
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

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (dist[i][j] > -1) continue;
            if (board[i][j] == '.') continue;
            dfs(i, j, board[i][j]);
        }
    }

    print();
}