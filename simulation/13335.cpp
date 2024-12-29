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
    cout << "push-> que size: " << que.size() << "\n";
    que.pop();
    cout << "pop-> que size: " << que.size() << "\n";
    sum += arr[0];
    cout << "sum: " << sum << "\n";

    for (int i = 1; i < n; i++) {
        int cur_sum = sum + arr[i];
        if (cur_sum <= l) {
            cout << "if(i: " << i << ")\n";
            que.push(arr[i]);
            sum -= que.front();
            que.pop();
            sum += arr[i];
            cnt++;
        }
        else {
            cout << "else(i: " << i << ")\n";
            while(1) {
                sum -= que.front();
                que.pop();
                que.push(0);
                cnt++;
                int cur_sum = sum + arr[i];
                if (cur_sum <= l) break;
            }

            que.push(arr[i]);
            sum -= que.front();
            que.pop();
            sum += arr[i];
            cnt++;
        }
    }

    cout << cnt;
}