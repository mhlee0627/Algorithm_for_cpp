#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
int city[50][50];
int dist[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> chickenList;
vector<pair<int, int>> house;
queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clearDist() {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        dist[i][j] = -1;
}

int getDist(int x, int y) {
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        pair<int, int> curPos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curPos.first + dirX[i];
            int ny = curPos.second + dirY[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[curPos.first][curPos.second] + 1;
            q.push({nx, ny});
        }
    }

    int sum = 0;
    for (auto elem : house) {
        sum += dist[elem.first][elem.second];
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        cin >> temp;
        city[i][j] = temp;
        
        if (temp == 2) {
            chicken.push_back({i, j});
        }
        else if (temp == 1) {
            house.push_back({i, j});
        }        
    }

    int chick_i = 0;
    for (auto elem : chicken) {
        chickenList.push_back({getDist(elem.first, elem.second), chick_i++});
        clearDist();
    }

    for (auto elem : chickenList) {
        cout << "chickenList1: " << elem.first << ", " << elem.second << "\n";
    }

    sort(chickenList.begin(), chickenList.end());

    for (auto elem : chickenList) {
        cout << "chickenList2: " << elem.first << ", " << elem.second << "\n";
    }


    
}   
