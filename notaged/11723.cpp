#include <bits/stdc++.h>
using namespace std;

int m;
string cmd;
int x;
bool vis[21];

void add(int x) {
    vis[x] = true;
}

void remove(int x) {
    vis[x] = false;
}

void check(int x) {
    cout << vis[x] << "\n";
}

void toggle(int x) {
    vis[x] = vis[x] ? false : true;
}

void all() {
    for (int i = 1; i < 21; i++)
        vis[i] = true;
}

void empty() {
    for (int i = 1; i < 21; i++)
        vis[i] = false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            add(x);
        }
        else if (cmd == "remove") {
            cin >> x;
            remove(x);
        }
        else if (cmd == "check") {
            cin >> x;
            check(x);
        }
        else if (cmd == "toggle") {
            cin >> x;
            toggle(x);
        }
        else if (cmd == "all") {
            all();
        }
        else {
            empty();
        }
    }
}

