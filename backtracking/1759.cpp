#include <bits/stdc++.h>
using namespace std;

int l, c;
char input[15];
bool isUsed[15];
char ret[15];

bool check() {
    bool vowel = false;
    int cons_cnt = 0;

    for (int i = 0; i < l; i++) {
        if (ret[i] == 'a' || ret[i] == 'e' || ret[i] == 'i' || ret[i] == 'o' || ret[i] == 'u') vowel = true;
        else {
            cons_cnt++;
        }
    }
    return vowel && (cons_cnt >= 2);
}

void func(int r, int k) {
    if (k == l) {
        if (check()) {
            for (int i = 0; i < k; i++) {
                cout << ret[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = r; i < c; i++) {
        if (!isUsed[i]) {
            ret[k] = input[i];
            isUsed[i] = true;
            func(i, k+1);
            isUsed[i] = false;
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char temp;
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> input[i];
    }

    sort(input, input+c);

    func(0, 0);
}