#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    string tmp;
    int cur_idx = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+') {
            tmp = s.substr(cur_idx, (i-cur_idx));
            vec.push_back(tmp);
            vec.push_back("+");
            cur_idx = i+1;
        }
        else if (s[i] == '-') {
            tmp = s.substr(cur_idx, (i-cur_idx));
            vec.push_back(tmp);
            vec.push_back("-");
            cur_idx = i+1;
        }
        else if (s[i] == 0) {
            tmp = s.substr(cur_idx, (i-cur_idx));
            vec.push_back(tmp);
        }
        else {
            continue;
        }
    }

    bool isplus = false;
    bool isminus = false;
    int psum = stoi(vec[0]);
    int msum = 0;
    
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == "+") {
            isplus = true;
        }
        else if (vec[i] == "-") {
            isminus = true;
        }
        else {
            if (isminus) {
                msum += stoi(vec[i]);
            } 
            else {
                psum += stoi(vec[i]);
            } 

        }
    }

    cout << psum - msum << '\n';
}