#include <bits/stdc++.h>
#include <stack>
using namespace std;

stack<int> st;

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
        
        if (cmd == "push")
        {
            cin >> X;
            st.push(X);
        }
        else if (cmd == "pop")
        {
            if (st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << st.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (st.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
    }
}