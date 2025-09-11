#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> vote;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> vec;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int in;
            cin >> in;
            vec.push_back({in, i});
            sum += in;
        }

        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        
        if (vec[0].first == vec[1].first) {
            cout << "no winner" << endl;
        }
        else if (vec[0].first > sum/2) {
            cout << "majority winner " << vec[0].second << endl;
        }
        else {
            cout << "minority winner " << vec[0].second << endl;
        }
    }
}