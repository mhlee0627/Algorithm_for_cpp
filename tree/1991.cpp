#include <bits/stdc++.h>
using namespace std;

#define offset 0x40

int n;
int lc[30];
int rc[30];

void preorder(char cur) {
    cout << (char)(cur + offset);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(char cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << (char)(cur + offset);
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(char cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << (char)(cur + offset);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    char node, lnode, rnode;
    for (int i = 0; i < n; i ++) {
        cin >> node >> lnode >> rnode;
        
        if (lnode != '.') {
            lc[node - offset] = lnode - offset;
        }

        if (rnode != '.') {
            rc[node - offset] = rnode - offset;
        }
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    cout << '\n';
}