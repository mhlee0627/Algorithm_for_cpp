#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000000];
int b[1000000];

int a_i;
int b_i;

void func(int k) {
    for (int i = 0; i < k; i++) {
        if (a_i == n) {
            cout << b[b_i++] << " ";
        }
        else if (b_i == m) {
            cout << a[a_i++] << " ";
        }
        else if (a[a_i] <= b[b_i]) {
            cout << a[a_i++] << " ";
        }
        else if (a[a_i] > b[b_i]) {
            cout << b[b_i++] << " ";
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    func(n+m);
}