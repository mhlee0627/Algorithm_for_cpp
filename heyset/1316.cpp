#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int cnt;
int isArpa[26];
bool isGroup = 1;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;

        int pre = str[0]-'a';
        isArpa[pre] = 1;
        for (int i = 1; i < str.size(); i++) {
            int cur = str[i]-'a';
            if (pre == cur) continue;

            if (isArpa[cur] >= 1) {
                isGroup = false;
                // cout << "break: " << str << '\n';
                break;
            }
            else {
                isArpa[cur] = isArpa[cur]+1;
            }

            pre = cur;
        }

        if (isGroup) cnt++;

        isGroup = true;
        for (int i = 0; i < 26; i++) isArpa[i] = 0;
    }

    cout << cnt << '\n';
}