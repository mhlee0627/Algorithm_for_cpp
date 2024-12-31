#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr[10];
int cnt;

int checksum(int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    return sum;
}

void func(int k) {
    if (checksum(k) == n) {
        cnt++;
        return;
    }
    else if (checksum(k) > n) {
        return;
    }

    if (k == n) {
        return;
    }

    for (int i = 1; i < 4; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        func(0);
        cout << cnt << "\n";
        cnt = 0;
    }
}