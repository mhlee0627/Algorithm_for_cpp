#include <bits/stdc++.h>
using namespace std;

int t;
string str;
list<char> l;
int cur_pos;

void func(char c) {
    if (c == '<') {
        cur_pos--;
        if (cur_pos < 0) cur_pos = 0;
    }
    else if (c == '>') {
        if (l.size()-1 >= cur_pos) {
            cur_pos++;
        }
    }
    else if (c == '-') {
        if (cur_pos == 0) return;

        auto it = l.begin();
        advance(it, cur_pos-1);
        l.erase(it);
        cur_pos--;
        if (cur_pos < 0) cur_pos = 0;
    }
    else {
        auto it = l.begin();
        advance(it, cur_pos);
        l.insert(it, c);
        cur_pos++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        cur_pos = 0;
        for (int j = 0; j < str.size(); j++) {
            func(str[j]);
        }

        for (auto elem : l) {
            cout << elem;
        }
        cout << "\n";
        l.clear();
    }
}