#include <bits/stdc++.h>
using namespace std;

int n, m;
string name1;
string name2;

map<char, int> ma= {
    {'A', 3},
    {'B', 2},
    {'C', 1},
    {'D', 2},
    {'E', 4},
    {'F', 3},
    {'G', 1},
    {'H', 3},
    {'I', 1},
    {'J', 1},
    {'K', 3},
    {'L', 1},
    {'M', 3},
    {'N', 2},
    {'O', 1},
    {'P', 2},
    {'Q', 2},
    {'R', 2},
    {'S', 1},
    {'T', 2},
    {'U', 1},
    {'V', 1},
    {'W', 1},
    {'X', 2},
    {'Y', 2},
    {'Z', 1}
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> name1 >> name2;

    queue<char> nq1;
    queue<char> nq2;

    for (int i = 0; i < n; i++) {
        nq1.push(name1[i]);
    }

    for (int i = 0; i < m; i++) {
        nq2.push(name2[i]);
    }

    vector<int> vec;
    int len = n > m ? n : m;
    for (int i = 0; i < len; i++) {
        if (!nq1.empty()) {
            vec.push_back(ma[nq1.front()]);
            nq1.pop();
        }

        if (!nq2.empty()) {
            vec.push_back(ma[nq2.front()]);
            nq2.pop();
        }
    }

    while (vec.size() != 2) {
        vector<int> tmp;
        for (int i = 0; i < vec.size()-1; i++) {
            int ret = vec[i] + vec[i+1];
            tmp.push_back(ret%10);
        }

        vec.clear();
        vec = tmp;
    }

    cout << vec[0] * 10 + vec[1] << "%\n";
}