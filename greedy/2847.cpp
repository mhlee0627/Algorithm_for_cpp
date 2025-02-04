#include <bits/stdc++.h>
using namespace std;

int n;
int score[105];
int cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    for (int i = n-1; i > 0; i--) {
        while (score[i] <= score[i-1]) {
            score[i-1]--;
            cnt++;
        }
    }

    cout << cnt << '\n';
}