#include <bits/stdc++.h>
using namespace std;

int n;
string in;
char s[50];
int cur;

void push(int x) {
    s[cur++] = x;
}

char pop() {
    if (cur == 0) return -1;

    return s[--cur];
}

bool empty() {
    return !cur;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == '(') {
                push('(');
                // cout << i << " push\n";
            }
            else {
                if (pop() == -1) {
                    push('x');
                    break;
                }
                // cout << i << " pop\n";
            }
        }

        if (empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        cur = 0;
    }


}
