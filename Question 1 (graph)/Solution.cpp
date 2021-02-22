#include <iostream>
using namespace std;

bool V[100][100];
bool vis[100];
int n,e;
int l,k;
int path[100];
void input(){
    cin>>n>>e;
    for(int i =0;i<e;i++){
        int u, v;
        cin>>u>>v;
        V[u][v]=true;
    }
}
void reset(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            V[i][j]=false;
        }
        vis[i]=false;
        path[i]=-1;
    }
    k=-2;
    l=-2;
}
int recur(int node , int counter){
    path[counter] = node;
    for(int y=0;y<n;y++){
        if(V[node][y]){
            if(vis[y]){
                k=y;
                l=node;
                return -1;
            }
            vis[y]=true;
            int i = recur(y,counter+1);
            if(i==-1){
                return -1;
            }
            vis[y]=false;
        }
    }
}
void driver(){
    for(int x =0;x<n;x++){
        vis[x] = true;
        path[0] =x;
        for(int y = 0 ; y<n ; y++){
            if(V[x][y]){
                if(vis[y]){
                    if(x==y){
                        k=-1;
                        return;
                    }
                }
                vis[y]=true;
                int ret= recur(y,1);
                if(ret==-1){
                    return;
                }
                vis[y]=false;
            }
        }
    }
}
void output(){
    cout<<endl;
    if(k==-2){
        cout<<-1<<endl;
        return;
    }
    if(k==-1){
        cout<<path[0]<<endl;
        return;
    }
    int start_idx=0;
    for(int i =0 ; i<100 ; i++){
        if(path[i] == k){
            start_idx = i;
        }
    }
    for(int i=start_idx;i<100;i++){
        if(path[i] == l){
            cout<<path[i]<<"->";
            break;
        }
        cout<<path[i]<<"->";
    }
    cout<<path[start_idx];
    cout<<endl;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        reset();
        input();
        driver();
        output();
    }
    return 0;
}