#include <bits/stdc++.h>
using namespace std;

int n;
struct ST {
    string name;
    int kor, eng, math;
};

vector<ST> vec;

bool cmp(ST& a, ST& b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) {
        return a.name < b.name;
    } 
    else if (a.kor == b.kor && a.eng == b.eng) {
        return a.math > b.math;
    }
    else if (a.kor == b.kor) {
        return a.eng < b.eng;
    }
    else {
        return a.kor > b.kor;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string str;
    int s_1, s_2, s_3;
    for (int i = 0; i < n; i++) {
        cin >> str >> s_1 >> s_2 >> s_3;
        vec.push_back({str, s_1, s_2, s_3});
    }

    sort(vec.begin(), vec.end(), cmp);

    for (auto& elem : vec) {
        cout << elem.name << "\n";
    }
}