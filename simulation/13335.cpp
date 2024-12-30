#include <bits/stdc++.h>
using namespace std;

int n, w, l;
int arr[1000];
queue<int> que;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < w; i++) {
        que.push(0);
    }

    int sum = 0;
    int cnt = 1;
    que.push(arr[0]);
    que.pop();
    sum += arr[0];

    int arr_idx = 1;
    while (!que.empty()) {
        // cout << "(cnt: " << cnt << "| arr_idx: " << arr_idx << ")\n";

        if (arr_idx == n) {
            que.pop();
            cnt++;
            // cout << "dum pop(cnt: " << cnt << ")\n";
            continue;
        }

        int cur_sum = sum - que.front() + arr[arr_idx];
        
        if (cur_sum <= l) {
            // cout << "if(i: " << arr_idx << ")\n";
            que.push(arr[arr_idx]);
            sum -= que.front();
            que.pop();
            sum += arr[arr_idx++];
            cnt++;
        }
        else {
            // cout << "else(i: " << arr_idx << ")\n";
            que.push(0);
            sum -= que.front();
            que.pop();
            cnt++;
        }
    }

    cout << cnt;
}