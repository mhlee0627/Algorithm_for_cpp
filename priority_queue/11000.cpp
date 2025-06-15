#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> course;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        course.push_back({s, t});
    }

    sort(course.begin(), course.end());

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++) {
        q.push(course[i].second);

        if (q.top() <= course[i].first) {
            q.pop();
        }
    }

    cout << q.size() << '\n';
}