#include <bits/stdc++.h>
using namespace std;

string in;
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> in;
    int len = in.size();
    int integer = stoi(in);

    int i;
    for (i = len-1; i > 0; i--) {
        vec.push_back(integer / static_cast<int>(pow(10, i)));
        integer %= static_cast<int>(pow(10, i));
    }

    vec.push_back(integer % 10);

    sort(vec.begin(), vec.end(), greater<int>());

    for (auto elem : vec) {
        cout << elem;
    }
    cout << '\n';
}