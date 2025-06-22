#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr[10005];
deque<int> dq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> arr[i];

        sort(arr, arr+n);

        for (int i = 0; i < n; i++) {
            if (i%2 == 0) dq.push_back(arr[i]);
            else dq.push_front(arr[i]);
        }

        int cur = dq.front();
        dq.pop_front();
        int ret = 0;
        for (auto elem : dq) {
            ret = max(ret, abs(cur-elem));
            cur = elem;
        }

        dq.clear();

        cout << ret << '\n';
    }
}