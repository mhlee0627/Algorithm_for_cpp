#include <bits/stdc++.h>
using namespace std;

int n, m;
int tree[1000005];
int max_h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> tree[i];

    sort(tree, tree+n);

    int st = 1;
    int en = tree[n-1];
    while (st <= en) {
        int mid = (st+en)/2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                sum += (tree[i] - mid);
            }
        }

        if (sum >= m) {
            max_h = max(max_h, mid);
            st = mid+1;
        }
        else {
            en = mid-1;
        }
    }

    cout << max_h << '\n';
}