#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n, input;
    cin >> m >> n;

    vector<int> snacks;

    for(int i=0; i<n; i++){
        cin >> input;
        snacks.push_back(input);
    }

    sort(snacks.begin(), snacks.end());

    int low = 1;
    int high = snacks[n-1];

    int result = 0;

    while(low <= high){
        int mid = (low + high)/2;

        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += snacks[i]/mid;    
        }

        if(cnt < m) {
            high = mid - 1;
            
        }
        else {
            result = mid;
            low = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}