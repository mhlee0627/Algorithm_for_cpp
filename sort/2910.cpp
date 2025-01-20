#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> order;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second) {
        return order[p1.first] < order[p2.first];
    }
    else {
        return p1.second > p2.second;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    map<int, int> freq;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        freq[tmp]++;

        if (order[tmp] == 0) {
            order[tmp] = i+1;
        }
    }

    vector<pair<int, int>> vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(), cmp);

    for (auto elem : vec) {
        for (int i = 0; i < elem.second; i++) {
            cout << elem.first << " ";
        }
    }
}