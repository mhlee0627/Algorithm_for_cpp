#include <bits/stdc++.h>
#include <list>
using namespace std;

list<uint16_t> lt;
vector<uint16_t> vec;

list<uint16_t>::iterator eraseAndNextIterator(list<uint16_t>::iterator iter, uint16_t k)
{
    for (int i = 0; i < k-1; i++)
    {
        iter++;
        if (iter == lt.end())
        {
            iter = lt.begin();
            if (iter == lt.end())
                return iter;
        }
    }
    // cout << "cur: " << *iter << endl;
    vec.push_back(*iter);

    auto next_iter = lt.erase(iter);
    if (next_iter == lt.end())
    {
        next_iter = lt.begin();
        if (next_iter == lt.end())
            return next_iter;
    }
    // cout << "===== next: " << *next_iter << endl;

    return eraseAndNextIterator(next_iter, k);
}

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
    
    uint16_t N;
    uint16_t K;

    cin >> N;
    cin >> K;

    for (uint16_t i = 1; i < N + 1; i++)
    {
        lt.push_back(i);
    }

    eraseAndNextIterator(lt.begin(), K);

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        if (i == (N-1))
        {
            cout << vec[i] << ">";
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }

}