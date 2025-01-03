#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec(1000000);

int getTree(int h) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (vec[i] - h);
    }

    return sum;
}

int findHeight() {
    int i;
    for (i = 1; i < n+1; i++) {
        if (i == n) {
            return -1;
        }
        
        int h = vec[i];
        int k = getTree(h);
        if (k >= m) break;
    }

    return i;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.begin()+n, greater<int>());
    for (int i = 0; i < n; i++)
        cout << "sort: " << vec[i] << " ";
    cout << "\n";

    cout << "find: " << findHeight() << "\n";

    int idx = findHeight();
    int interval = vec[idx-1] - vec[idx];
    int puls = 0;
    for (puls = 0; puls < interval; puls++) {
        if (m <= getTree(vec[idx + puls])) break;
        cout << "puls.. : " << puls << "\n";
    }

    cout << "h: " << vec[idx] + puls << "\n";

}