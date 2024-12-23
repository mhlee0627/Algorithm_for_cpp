#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000000];
int head, tail;
string cmd;
int x;

void push(int x) {
    arr[head++] = x;
}

void pop() {
    if (head == tail) {
        cout << "-1\n";
    }
    else {
        cout << arr[tail] << "\n";
        tail++;
    }
}

void size() {
    cout << head - tail << "\n";
}

void empty() {
    if (head == tail)
        cout << "1\n";
    else
        cout << "0\n";
}

void front() {
    if (head == tail) {
        cout << "-1\n";
    }
    else {
        cout << arr[tail] << "\n";
    }
}

void back() {
    if (head == tail) {
        cout << "-1\n";
    }
    else {
        cout << arr[head-1] << "\n";
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        if (cmd == "push") {
            cin >> x;
            push(x);
        }
        else if (cmd == "pop") {
            pop();
        }
        else if (cmd == "size") {
            size();
        }
        else if (cmd == "empty") {
            empty();
        }
        else if (cmd == "front") {
            front();
        }
        else {
            back();
        }
    }
}