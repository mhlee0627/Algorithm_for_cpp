#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> vowel;
vector<char> cons;
char ret[15];

// positin backtracking
int p_ret[15];


void func(int k) {
    if (k == l) {
        for (int i = 0; i < k; i) {
            
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char temp;
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> temp;
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
            vowel.push_back(temp);
        else
            cons.push_back(temp);
    }



    

}