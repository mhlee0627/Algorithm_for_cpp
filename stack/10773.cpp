#include <bits/stdc++.h>
using namespace std;

int k;
int curVal;
int arr[100000];
int idx;

void push(int x) {
    arr[idx] = x;
    idx++;
}

int pop() {
    idx--;
    return arr[idx];
}

bool empty() {
    return idx == 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> curVal;
        if (curVal == 0) {
            if (!empty()) {
                int tmp = pop();
                // cout << "pop: " << tmp << "\n";
            }
        }
        else {
            // cout << "puch: " << curVal << "\n";
            push(curVal);
        }
    }
    
    unsigned long long sum = 0;
    while(!empty()) {
        int cur = pop();
        // cout << cur << "\n";
        sum += cur;
    }

    cout << sum;
}

