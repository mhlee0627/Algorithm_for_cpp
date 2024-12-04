#include <bits/stdc++.h>
#include <list>
using namespace std;

list<char> lt;

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
    string str;
    char cmd;
    int cnt;

    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        lt.push_back(str[i]);
    }
    auto cursor = lt.end();

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        cin >> cmd;
        switch(cmd)
        {
            case 'L':
            {
                if (cursor != lt.begin())
                    cursor--;
                break;
            }
            case 'D':
            {
                if (cursor != lt.end())
                    cursor++;
                break;
            }
            case 'B':
            {
                if (cursor != lt.begin())
                {
                    cursor--;
                    cursor = lt.erase(cursor);
                }
                break;
            }
            case 'P':
            {
                char add;
                cin >> add;
                lt.insert(cursor, add);
                break;
            }
        }
    }
    
    for (auto elem : lt)
        cout << elem;

}