#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> freq[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp >= 0) {
            freq[temp].first++;
        }
        else {
            freq[abs(temp)].second++;
        }
    }

    for (int i = 1000000; i > -1; i--) {
        for (int k = freq[i].second; k > 0; k--) {
            cout << (-1 * i) << "\n";
        }
    }

    for (int i = 0; i < 1000001; i++) {
        for (int k = freq[i].first; k > 0; k--) {
            cout << i << "\n";
        }
    }
}