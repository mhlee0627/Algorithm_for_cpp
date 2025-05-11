#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> player_result[51];
int player_order_arr[11];
queue<int> player_order;
bool vis[11];
int max_v;

// 얻은 점수 반환
int play_game(int inning) {
    int score = 0;
    int out = 0;
    queue<bool> ru;

    while (out != 3) {
        int player = player_order.front(); 
        player_order.pop();
        player_order.push(player);

        // cout << "cur player->" << player << "...: ";
        // cout << "cur action->" << player_result[inning][player] << "...: ";
        switch(player_result[inning][player - 1])
        {
            case 1:
                ru.push(1);
                if (ru.size() == 4) {
                    if (ru.front()) {
                        // cout << "1.. score++...";
                        score++;
                    }
                    ru.pop();
                }
                break;

            case 2:
                ru.push(1);
                ru.push(0);
                while (ru.size() >= 4) {
                    if (ru.front()) {
                        // cout << "2.. score++...";
                        score++;
                    }
                    ru.pop();
                }
                break;

            case 3:
                ru.push(1);
                ru.push(0);
                ru.push(0);
                while (ru.size() >= 4) {
                    if (ru.front()) {
                        // cout << "3.. score++...";
                        score++;
                    } 
                    ru.pop();
                }    
                break;

            case 4:
                ru.push(1);
                while (!ru.empty()) {
                    if (ru.front()) {
                        // cout << "4.. score++...";
                        score++;
                    } 
                    ru.pop();
                }    
                break;

            case 0:
                out++;
                break;

            default:
                cout << "default.. ";
                break;
        }
    }

    return score;
}

void func(int k) {
    if (k == 8) {
        for (int i = 0; i < 8; i++) {
            if (i == 3) player_order.push(1);
            player_order.push(player_order_arr[i]);
        }

        int t_score = 0;
        for (int i = 1; i <= n; i++) {
            // cout << i << " play inning: " << play_game(i) << '\n';
            t_score += play_game(i);
        }
        
        max_v = max(max_v, t_score);

        while (!player_order.empty()) player_order.pop();

        return;
    }

    for (int i = 2; i <= 9; i++) {
        if (!vis[i]) {
            player_order_arr[k] = i;
            vis[i] = true;
            func(k+1);
            vis[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            int in;
            cin >> in;
            player_result[i].push_back(in);
        }
    }

    func(0);

    cout << max_v << '\n';

    // func(0);
    // cout << "player odrer: ";
    // for (int i = 1; i < 10; i++) {
    //     player_order.push(i);
    //     cout << i << ' ';
    // }
    // cout << '\n';

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " play inning: " << play_game(i) << '\n';
    // }
}