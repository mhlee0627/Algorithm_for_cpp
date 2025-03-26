#include <bits/stdc++.h>
using namespace std;

int n;
int origin_arr[1000005];
int sort_arr[1000005];
vector<int> uniq_vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> origin_arr[i];
        sort_arr[i] = origin_arr[i];
    }
    
    sort(sort_arr, sort_arr+n);

    sort_arr[n] = 0x7fffffff;

    for (int i = 0; i < n; i++) {
        if (sort_arr[i] != sort_arr[i+1]) {
            uniq_vec.push_back(sort_arr[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << lower_bound(uniq_vec.begin(), uniq_vec.end(), origin_arr[i]) - uniq_vec.begin() << ' ';
    }
    cout << '\n';

    

}