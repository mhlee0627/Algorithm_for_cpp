#include <bits/stdc++.h>
using namespace std;

int n, x;
bool arr[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp] = true;
    }
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < 1000001; i++) {
        if (arr[i] == false) continue;
        
        int find_num = (x - i);
        if (find_num <= 0 || find_num > 1000000 || find_num == i) continue;
        
        if (arr[find_num] == true) {
            // cout << i << ", " << find_num << "\n";
            cnt++;
            arr[find_num] = false;
        }
    }

    cout << cnt;
}