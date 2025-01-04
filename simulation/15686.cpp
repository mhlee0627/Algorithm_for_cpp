#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
int city[50][50];
int dist[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected_chicken;
vector<pair<int, int>> chickenList;
vector<pair<int, int>> house;
vector<int> minimun_chicken_dist;
unordered_map<int, vector<int>> chickenDist;
queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int arr[13];
int ret[13];
bool vis[13];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void clearDist() {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        dist[i][j] = -1;
}

void bfs(int x, int y) {
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

    // cout << "\n";
    // print();
    // cout << "\n";

    for (int i = 0; i < house.size(); i++) {
        chickenDist[i].push_back(dist[house[i].first][house[i].second]);
    }
}

int getMinimumDist() {
    for (auto elem : selected_chicken) {
        bfs(elem.first, elem.second);
        clearDist();
    }

    int sum = 0;
    for (auto& elem : chickenDist) {
        sort(elem.second.begin(), elem.second.end());
        // cout << "chikenDist: " << elem.second[0] << "\n";
        sum += elem.second[0];
        elem.second.clear();
    }

    return sum;
}

void func(int r, int k) {
    if (k == m) {
        // for (int i = 0; i < k; i++) {
        //     cout << ret[i] << " ";
        // }
        // cout << "-----> ";

        for (int i = 0; i < k; i++) {
            selected_chicken.push_back(chicken[ret[i]]);
        }
        // cout << "selected_chicken: " << selected_chicken[selected_chicken.size()-1].first << ", " << selected_chicken[selected_chicken.size()-1].second  << "\n";

        minimun_chicken_dist.push_back(getMinimumDist());
        // cout << minimun_chicken_dist[minimun_chicken_dist.size()-1] << "\n";

        selected_chicken.clear();

        return;
    }

    for (int i = r; i < chicken.size(); i++) {
        if (!vis[i]) {
            ret[k] = arr[i];
            vis[i] = true;
            func(i+1, k+1);
            vis[i] = false;
        }
    }
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

    int chicken_cnt = chicken.size();
    for (int i = 0; i < chicken_cnt; i++) {
        arr[i] = i;
    }

    // m개의 치킨집의 조합을 가지는 순열 찾아내기.. backtracking 이용하여
    func(0, 0);

    sort(minimun_chicken_dist.begin(), minimun_chicken_dist.end());

    cout << minimun_chicken_dist[0];
}   
