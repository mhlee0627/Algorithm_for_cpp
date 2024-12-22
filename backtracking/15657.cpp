#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> vec(10);
int ret[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k-1; i++) {
            if (ret[i] > ret[i+1]) return;
        }

        for (int i = 0; i < k; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ret[k] = vec[i];
        func(k+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.begin() + n);

    func(0);
}