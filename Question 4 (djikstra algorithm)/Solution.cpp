#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[100][100];
int x[100];
int y[100];
int w[50];
int cost[100];
bool vis[100];
int v[100];
void setmatrix(){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            a[i][j] = abs(x[j] - x[i])+ abs(y[j]-y[i]);
        }
    }
    int j=1;
    for(int i = 1 ; i <n-2 ; i++){
        a[i][i+1] = w[j];
        a[i+1][i] = w[j];
        j++;
    }
    
}
int findmin(){
    int mn =INT_MAX;
    int k = -1;
    for(int i = 0 ; i <n; i++){
        if(!vis[i] && mn>cost[i]){
            mn = cost[i];
            k = i;
        }
    }
    return k;
}
int mincost(){
    for(int i =0; i<n ; i++){
        vis[i] = false;
        cost[i] = INT_MAX;
        
    }
    cost[0] = 0;
    int z=1;
    while(z){
        int j = findmin();
        vis[j] = true;
        if(j == n-1){
            return cost[j];
        }
        for(int i = 0 ; i<n ; i++){
            if(!vis[i] && (a[j][i] + cost[j] <cost[i])){
                cost[i] = cost[j] + a[j][i];
            }
        }
    }
    return -1;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	   
	    cin>>m;
	    n=m*2+1;
	    int i = 0;
	    cin>>x[i]>>y[i];
	    i++;
	    cin>>x[n-1]>>y[n-1];
	    int j = 1;
	    while(i<n-1){
	        cin>>x[i]>>y[i++];
	        cin>>x[i]>>y[i++];
	        cin>>w[j++];
	        
	    }
	    setmatrix();
	    int ans = mincost();
	    cout<<ans<<endl;
	}
	return 0;
}