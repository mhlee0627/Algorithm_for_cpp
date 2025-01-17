#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' && s[i+1] == ')') {
            cnt += st.size();
            i++;
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            cnt++;
            st.pop();
        }
    }

    cout << cnt;
}