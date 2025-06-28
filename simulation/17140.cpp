#include <bits/stdc++.h>
using namespace std;

int board[105][105];
int r, c, k;
int curRlen = 3;
int curClen = 3;

void print_brd() {
    cout << '\n';
    for (int i = 0; i < curRlen; i++) {
        for (int j = 0; j < curClen; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int r_act() {
    int maxv = 0;
    vector<int> size;

    for (int i = 0; i < curRlen; i++) {
        map<int, int> m;
        for (int j = 0; j < curClen; j++) {
            if (board[i][j] == 0) continue;

            if (m.find(board[i][j]) != m.end()) {
                m[board[i][j]]++;
            }
            else {
                m[board[i][j]] = 1;
            }
        }

        vector<pair<int, int>> vec;
        for (auto elem : m) {
            vec.push_back({elem.second, elem.first});
        }

        sort(vec.begin(), vec.end());

        int idx = 0;
        for (auto elem : vec) {
            if (idx == 100) break;
            board[i][idx++] = elem.second;
            if (idx == 100) break;
            board[i][idx++] = elem.first;
        }

        // for (int t = 0; t < idx; t++) {
        //     cout << board[i][t] << ' ';
        // }
        // cout << '\n';

        size.push_back(idx);
        maxv = max(maxv, idx);
    }

    for (int i = 0; i < curRlen; i++) {
        for (int t = size[i]; t < maxv; t++) {
            board[i][t] = 0;
        }
    }

    return maxv;
}

int c_act() {
    int maxv = 0;
    vector<int> size;

    for (int j = 0; j < curClen; j++) {
        map<int, int> m;
        for (int i = 0; i < curRlen; i++) {
            if (board[i][j] == 0) continue;

            if (m.find(board[i][j]) != m.end()) {
                m[board[i][j]]++;
            }
            else {
                m[board[i][j]] = 1;
            }
        }

        vector<pair<int, int>> vec;
        for (auto elem : m) {
            vec.push_back({elem.second, elem.first});
        }

        sort(vec.begin(), vec.end());

        int idx = 0;
        for (auto elem : vec) {
            if (idx == 100) break;
            board[idx++][j] = elem.second;
            if (idx == 100) break;
            board[idx++][j] = elem.first;
        }

        size.push_back(idx);
        maxv = max(maxv, idx);
    }

    for (int j = 0; j < curClen; j++) {
        for (int t = size[j]; t < maxv; t++) {
            board[t][j] = 0;
        }
    }

    return maxv;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    int sec = 0;
    while (sec != 101) {
        if (board[r-1][c-1] == k) {
            cout << sec << '\n';
            return 0;
        }

        sec++;
        if (curRlen >= curClen) curClen = r_act();
        else curRlen = c_act();

        // cout << "after " << sec << " sec..\n";
        // print_brd();
        // cout << '\n';
    }

    cout << -1 << '\n';

    // curClen = r_act();
    // curRlen = c_act();

    // print_brd();
}