#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> vec;

int get_total_num(string& s) {
    int rlt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            rlt += (s[i] - '0');
        }
    }
    return rlt;
}


bool cmp(string& a, string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        int a_num = get_total_num(a);
        int b_num = get_total_num(b);
        if (a_num != b_num) {
            return a_num < b_num;
        }
    }

    return a < b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end(), cmp);

    for (auto& elem : vec) {
        cout << elem << "\n";
    }
}