#include <bits/stdc++.h>
#include <array>
using namespace std;

#define MAX_NUM 10000
int dat[2*MAX_NUM + 1];
int head = MAX_NUM, tail = MAX_NUM;

void push_front(int x)
{
    dat[--head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int front()
{
    return dat[head];
}

int back()
{
    return dat[tail-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int N, X;
    string cmd;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> X;
            push_front(X);
        }
        else if (cmd == "push_back")
        {
            cin >> X;
            push_back(X);
        }
        else if (cmd == "pop_front")
        {
            if (head == tail)
                cout << "-1\n";
            else {
                cout << front() << "\n";
                pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (head == tail)
                cout << "-1\n";
            else {
                cout << back() << "\n";
                pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << tail - head << "\n";
        }
        else if (cmd == "empty")
        {
            if (head == tail)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd == "front")
        {
            if (head == tail)
                cout << "-1\n";
            else
                cout << front() << "\n";
        }
        else
        {
            if (head == tail)
                cout << "-1\n";
            else
                cout << back() << "\n";
        }
    }


    return 0;
}