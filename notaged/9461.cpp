#include <bits/stdc++.h>
using namespace std;

int t, n;
unsigned long long arr[101] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 3; i < 100; i++) {
        arr[i] = arr[i-3] + arr[i-2];
    }

    // for (int i = 0; i < 100; i++)
    //     cout << arr[i] << "\n";

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n-1] << "\n";
    }
}