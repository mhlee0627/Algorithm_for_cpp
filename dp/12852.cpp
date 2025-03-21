#include <bits/stdc++.h>
using namespace std;

// pair<int, int> d[1000005];

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     d[1].first = 0;
//     d[1].second = 0;
//     d[2].first = 1;
//     d[2].second = 1;
//     d[3].first = 1;
//     d[3].second = 1;
//     for (int i = 4; i <= n; i++) {
//         if (i % 3 == 0 && i % 2 == 0) {
//             d[i].first = min(d[i/2].first, d[i/3].first) + 1;
//             d[i].second = d[i/2].first < d[i/3].first ? i/2 : i/3;
//         }
//         else if (i % 3 == 0) {
//             d[i].first = min(d[i-1].first, d[i/3].first) + 1;
//             d[i].second = d[i-1].first < d[i/3].first ? i-1 : i/3;
//         }
//         else if (i % 2 == 0) {
//             d[i].first = min(d[i-1].first, d[i/2].first) + 1;
//             d[i].second = d[i-1].first < d[i/2].first ? i-1 : i/2;
//         }
//         else {
//             d[i].first = d[i-1].first + 1;
//             d[i].second = i-1;
//         }
//     }

//     cout << d[n].first << "\n";

//     cout << n << " ";
//     int tmp = n;
//     for (int i = 0; i < d[n].first; i++) {
//         cout << d[tmp].second << " ";
//         tmp = d[tmp].second;
//     }

// }


// barkingdog solution

int d[1000005];
int pre[1000005];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i-1] + 1;
        pre[i] = i-1;

        if (i%2 == 0 && d[i] > d[i-2]+1) {
            d[i] = d[i/2] + 1;
            pre[i] = i/2;
        }

        if (i%3 == 0 && d[i] > d[i-3]+1) {
            d[i] = d[i/3] + 1;
            pre[i] = i/3;
        }
    }

    cout << d[n] << '\n';
    int cur = n;
    while (1) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = pre[cur];
    }
}