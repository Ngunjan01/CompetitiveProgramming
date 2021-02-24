#include <bits/stdc++.h>
using namespace std;
#define MAX 15
int ans;
int W,H;
int arr[MAX][MAX];
int vis[MAX][MAX];
int modd[6][2] = {{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{-1,1}};
int meven[6][2] = {{0,-1},{0,1},{1,0},{-1,0},{1,-1},{1,1}};

void rundfs(int i , int j , int val , int cnt){
    if(cnt == 4){
        if(ans<val){
            ans = val;
        }
        return;
    }
    for(int m = 0 ; m<6 ; m++){
        int x ;
        int y ;
        if(j%2){
            x = i + meven[m][0];
            y = j + meven[m][1];
        }
        else{
            x = i + modd[m][0];
            y = j + modd[m][1];
            
        }
        if(vis[x][y] == 0 && x>=0 && x<W && y>=0 && y<H){
            vis[x][y] = 1;
            rundfs(i,j,val+arr[x][y],cnt+1);
            rundfs(x,y,val+arr[x][y],cnt+1);
            vis[x][y]=0;
        }
    }
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    for(int i = 0; i<MAX ; i++){
	        for(int j = 0 ; j<MAX ; j++){
	            arr[i][j] = 0;
	            vis[i][j] = 0;
	        }
	    }
	    W=H=ans=0;
	    cin>>W>>H;
	    for(int i =0 ; i<W ;i++){
	        for(int j = 0 ; j<H; j++){
	            cin>>arr[i][j];
	        }
	    }
	    for(int i = 0 ; i<W ; i++){
	        for(int j = 0 ; j<H ; j++){
	            vis[i][j] = 1;
	            rundfs(i , j , arr[i][j] , 1);
	            vis[i][j] = 0;
	            
	        }
	    }
	    cout<<ans*ans<<endl;
	    
	}
	return 0;
}