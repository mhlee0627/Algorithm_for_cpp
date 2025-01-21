#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        vec.push_back(str.substr(i, str.size()-i));
    }

    sort(vec.begin(), vec.end());

    for (auto& elem : vec) {
        cout << elem << "\n";
    }
}