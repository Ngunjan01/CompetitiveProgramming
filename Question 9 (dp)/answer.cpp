#include <iostream>
using namespace std;
#define lim 500
int bal[lim];
int dp[lim][lim];
int n;

int solution(){
    for(int len = 1 ; len<= n ; len++){
        for(int i =0 ; i<=n-len ; i++){
            int j = i+len-1;
            for(int k = i ; k<=j ; k++){
                int leftVal = 1;
                int rightVal = 1;
                if(i!=0){
                    leftVal = bal[i-1];
                }
                if(j!= n-1){
                    rightVal= bal[j+1];
                }
                int before = 0;
                int after = 0;
                if(i!= k){
                    before=dp[i][k-1];
                }
                if(j!=k){
                    after = dp[k+1][j];
                }
                dp[i][j] = max(dp[i][j] , before+after+(leftVal*rightVal*bal[k]));
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    cin>>n;
    for(int i= 0 ; i<n; i++){
        int x;
        cin>>x;
        bal[i] = x;
    }
    cout<<solution()<<endl;
}
