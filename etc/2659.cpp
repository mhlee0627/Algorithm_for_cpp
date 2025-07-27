#include <bits/stdc++.h>
using namespace std;

int arr[4];
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int z = 1; z <= 9; z++) {
                    int sum = (1000*i) + (100*j) + (10*k) + z;
                    
                    int ref1 = (1000*j) + (100*k) + (10*z) + i;
                    int ref2 = (1000*k) + (100*z) + (10*i) + j;
                    int ref3 = (1000*z) + (100*i) + (10*j) + k;
                    
                    if (sum > ref1 || sum > ref2 || sum > ref3) continue;
                    
                    vec.push_back(sum);
                }
            }
        }
    }

    vector<int> tmp;
    tmp.push_back((1000*arr[0]) + (100*arr[1]) + (10*arr[2]) + arr[3]);
    tmp.push_back((1000*arr[1]) + (100*arr[2]) + (10*arr[3]) + arr[0]);
    tmp.push_back((1000*arr[2]) + (100*arr[3]) + (10*arr[0]) + arr[1]);
    tmp.push_back((1000*arr[3]) + (100*arr[0]) + (10*arr[1]) + arr[2]);

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == tmp[0]) {
            cout << i+1 << '\n';
        }
    }
}