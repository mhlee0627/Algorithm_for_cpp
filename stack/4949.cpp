#include <bits/stdc++.h>
using namespace std;

char arr[101];
int pos = 0;

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
    char text;
    string str;

    getline(cin, str);
    while(str != ".")
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '.')
                break;
            else if (str[i] == '(')
                push(str[i]);
            else if (str[i] == ')')
            {
                if (top() == '(')
                    pop();
                else {
                    push(str[i]);
                    break;
                }
            }
            else if (str[i] == '[')
                push(str[i]);
            else if (str[i] == ']')
            {
                if (top() == '[')
                    pop();
                else {
                    push(str[i]);
                    break;
                }
            }
            else {
                // nothing
            }
        }
    
        if (pos != 0)
        {
            cout << "no\n";
            pos = 0;
        }
        else
            cout << "yes\n";

        getline(cin, str);
    }
}