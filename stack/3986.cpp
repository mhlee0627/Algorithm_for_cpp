#include <bits/stdc++.h>
using namespace std;

char arr[100001];
int pos = 0;
int cnt = 0;

void push(char x)
{
    arr[pos++] = x;
}

void pop()
{
    pos--;
}

char top()
{
    return arr[pos-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int N = 0;
    string str;

    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (pos == 0)
                push(str[j]);
            else if (top() == str[j])
                pop();
            else
                push(str[j]);
        }

        if (pos == 0)
            cnt++;
        else
            pos = 0;
    }

    cout << cnt;

    return 0;
}