#include <bits/stdc++.h>
using namespace std;

int freq[2000001];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        freq[temp + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        while (freq[i]--) {
            cout << i - 1000000 << "\n";
        }
    }
}