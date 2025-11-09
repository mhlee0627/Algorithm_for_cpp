#include <bits/stdc++.h>
using namespace std;

int n;
char game;
int g;
set<string> s;
int member = 1;
int ret;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> game;
    
    if (game == 'Y') g = 2;
    else if (game == 'F') g = 3;
    else if (game == 'O') g = 4;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (s.find(name) != s.end()) {
            
        }
        else {
            s.insert(name);
            member++;
        }

        if (member == g) {
            ret++;
            member = 1;
        }
    }

    cout << ret << '\n';
}