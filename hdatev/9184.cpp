// #include <bits/stdc++.h>
// using namespace std;

// int a, b, c;
// long long dp[105][105][105];

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     for (int i = 1; i <= 101; i++) {
//         for (int j = 1; j <= 101; j++) {
//             for (int k = 1; k <= 101; k++) {
//                 if (i <= 51 || j <= 51 || k <= 51) {
//                     dp[i][j][k] = 1;
//                     continue;
//                 }

//                 if (i > 20+51 || j > 20+51 || k> 20+51) {
//                     dp[i][j][k] = dp[20+51][20+51][20+51];
//                     continue;
//                 }

//                 if (i < j && j < k) {
//                     dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
//                     continue;
//                 }

//                 dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
//             }
//         }
//     }

//     while (1)
//     {
//         cin >> a >> b >> c;
//         if (a == -1 && b == -1 && c == -1) break;

//         cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a+51][b+51][c+51] << '\n';
//     }
// }


#include<iostream>
using namespace std;

int dp[21][21][21]={0,};

int W(int a,int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }else if(a>20||b>20||c>20){
        return W(20,20,20);
    }else if(dp[a][b][c]!=0){
        return dp[a][b][c];
    }else if(a<b&&b<c){ 
        dp[a][b][c]=W(a,b,c-1)+W(a,b-1,c-1)-W(a,b-1,c);
    }else{
         dp[a][b][c]=W(a-1,b,c)+W(a-1,b-1,c)+W(a-1,b,c-1)-W(a-1,b-1,c-1);
    }
    return dp[a][b][c];
}
int main(){
    int a,b,c;
    
    while(true){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<W(a,b,c)<<"\n";
    }
}