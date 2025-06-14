#include <bits/stdc++.h>
using namespace std;

#define right 2
#define left  6

string str[5];
deque<int> w[5];
int k;
vector<pair<int, int>> turn;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 4; i++) {
        cin >> str[i];
        for (int j = 0; j <= 7; j++) {
            w[i].push_back(str[i][j] - '0');
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        turn.push_back({a, b});
    }
    
    for (auto t : turn) {
        deque<int> tmp[5];
        for (int x = 1; x <= 4; x++) tmp[x] = w[x];

        // cout << "turn: " << t.first s<< ", dir: " << t.second << '\n';

        int dir = t.second;
        for (int i = t.first+1; i <= 4; i++) {
            // 극이 다를때
            if (tmp[i-1][right] != tmp[i][left]) {
                // 시계 방향
                if (dir == 1) {
                    // cout << i << " is reverse clock turn" << endl;

                    auto cur = w[i].front();
                    w[i].pop_front();
                    w[i].push_back(cur);
                    dir = -1;
                }
                // 반시계 방향
                else {
                    // cout << i << " is clock turn" << endl;

                    auto cur = w[i].back();
                    w[i].pop_back();
                    w[i].push_front(cur);
                    dir = 1;
                }
            }
            // 극이 같을때
            else {
                break;
            }
        }

        int dir2 = t.second;
        for (int i = t.first-1; i > 0; i--) {
            // 극이 다를때
            if (tmp[i][right] != tmp[i+1][left]) {
                // 시계 방향
                if (dir2 == 1) {
                    // cout << i << " is reverse clock turn" << endl;

                    auto cur = w[i].front();
                    w[i].pop_front();
                    w[i].push_back(cur);
                    dir2 = -1;
                }
                else {
                    // cout << i << " is clock turn" << endl;

                    auto cur = w[i].back();
                    w[i].pop_back();
                    w[i].push_front(cur);
                    dir2 = 1;
                }
            }
            else {
                break;
            }
        }

        if (t.second == 1) {
            auto cur = w[t.first].back();
            w[t.first].pop_back();
            w[t.first].push_front(cur);
        }
        else {
            auto cur = w[t.first].front();
            w[t.first].pop_front();
            w[t.first].push_back(cur);
        }

        // for (int z = 1; z <= 4; z++) cout << w[z][0] << ' ';
        // cout << '\n';
    }

    cout << w[1][0] + w[2][0] * 2 + w[3][0] * 4 + w[4][0] * 8 << '\n';
}