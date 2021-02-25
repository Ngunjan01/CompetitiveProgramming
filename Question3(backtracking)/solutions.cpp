#include <bits/stdc++.h>
using namespace std;
int d[12][12];
int x[12];
int y[12];
int vis[12];
int n;
int min_dis = 1e9;
int abs(int x){
    if(x>0){
        return x;
    }
    else{
        return -x;
    }
}
void predistance(){
    for(int i =0 ; i<=n+1 ; i++){
        for(int j=0; j<=n+1;j++){
            d[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        }
    }
}
void calculate(int source, int dest , int dis_so_far){
    dis_so_far = dis_so_far+d[source][dest];
    if(dis_so_far > min_dis){
        return;
    }
    if(dest == n+1){
        for(int i = 0 ; i <= n+1 ; i++){
            if(vis[i] == 0){
                return;
            }
        }
        if(dis_so_far < min_dis){
            min_dis =dis_so_far;
        }
        return;
    }
    for(int i = 0 ; i <= n+1 ; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            calculate(dest , i , dis_so_far);
            vis[i]=0;
        }
    }
    
    
}
int main() {
    int t;
    cin>>t;
	while(t--){
	    memset(vis , 0 , sizeof(vis));
	    min_dis = 1e9;
	    cin>>n;
	    cin>>x[0]>>y[0];
	    cin>>x[n+1]>>y[n+1];
	    for(int j = 1 ; j<=n ; ++j){
	        cin>>x[j]>>y[j];
	       
	    }
	    predistance();
	    vis[0] = 1;
	    vis[n+1] = 0;
	    calculate(0,0,0);
	    cout<<t<<" "<<min_dis<<endl;
	}
	return 0;
}