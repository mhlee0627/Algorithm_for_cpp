#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51];
deque<int> dq;
int cnt;

void first_action() {
    dq.pop_front();
}

void second_action() {
    int tmp = dq.front();
    dq.pop_front();
    dq.push_back(tmp);
    cnt++;
}

void third_action() {
    int tmp = dq.back();
    dq.pop_back();
    dq.push_front(tmp);
    cnt++;
}

int get_right_dist(int k) {
    for (int i = 0; i < dq.size(); i++) {
        if (arr[k] == dq[i]) {
            return i;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n+1; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        if (arr[i] == dq.front()) {
            first_action();
        }
        else {
            
        }
    }

    cout << cnt;
}
