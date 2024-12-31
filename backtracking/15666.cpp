#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<int> vec;
int ret[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k-1; i++) {
            if (ret[i] > ret[i+1]) return;
        }
        
        for (int i = 0 ; i < k; i++) {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (tmp != vec[i]) {
            ret[k] = vec[i];
            tmp = vec[i];
            func(k+1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.begin() + n);

    func(0);
}