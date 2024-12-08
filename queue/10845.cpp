#include <bits/stdc++.h>
#include <array>
using namespace std;

#define MAX_NUM 100000

array<int, MAX_NUM> arr;
int head;
int tail;

void push(int x)
{
    arr[tail++] = x;
}

void pop()
{
    head++;
}

int front()
{
    return arr[head];
}

int back()
{
    return arr[tail-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int N, X;
    string cmd;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> X;
            push(X);
        }
        else if (cmd == "pop") {
            if (head == tail)
                cout << "-1\n";
            else {
                cout << front() << "\n";
                pop();
            }
        }
        else if (cmd == "size") {
            cout << tail - head << "\n";
        }
        else if (cmd == "empty") {
            if (head == tail)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd == "front") {
            if (head == tail)
                cout << "-1\n";
            else
                cout << front() << "\n";
        }
        else {
            if (head == tail)
                cout << "-1\n";
            else
                cout << back() << "\n";
        }
    }

    return 0;
}