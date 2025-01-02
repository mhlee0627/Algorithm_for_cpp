#include <bits/stdc++.h>
using namespace std;

int arr[10];
int ret[8];
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int size = s.size();
    const char *ptr = s.data();

    for (int i = 0; i < size; i++) {
        arr[ptr[i]-'0']++;
    }

    // for (int i = 0; i < 10; i++) {
    //     cout << arr[i] << " ";
    // }

    int temp = (arr[6] + arr[9] + 1) / 2;
    arr[6] = temp;
    int max = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) max = arr[i];
    }

    cout << max;
}
