#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int n, m, k;
bool board[101][101];
bool visit[101][101];

pair<int, int> lefttop;
pair<int, int> rightbot;
int cnt;
vector<int> space_list;

void check_board() {
    for (int i = lefttop.X; i < rightbot.X; i++) {
        for (int j = lefttop.Y; j < rightbot.Y; j++) {
            board[i][j] = 1;
        }
    }
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> lefttop.X >> lefttop.Y >> rightbot.X >> rightbot.Y;
        check_board();
        // print_board();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && visit[i][j] == 0) {
                q.push({i, j});
                visit[i][j] = 1;
                while (!q.empty()) {
                    pair<int, int> curPos = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = curPos.X + dirX[i];
                        int ny = curPos.Y + dirY[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] == 1 || visit[nx][ny] > 0) continue;
                        q.push({nx, ny});
                        visit[nx][ny] = 1;
                    }
                    cnt++;
                }
                space_list.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cout << space_list.size() << "\n";
    sort(space_list.begin(), space_list.end());
    for (auto elem : space_list) {
        cout << elem << " ";
    }
}