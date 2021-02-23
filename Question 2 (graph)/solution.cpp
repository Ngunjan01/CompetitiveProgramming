#include <bits/stdc++.h>
using namespace std;
#define R  10
#define C 10
struct node{
    int x, y,dist;
};
int row[] = {-1,0,0,1};
int col[] = {0,-1,1,0};
bool isvalid(int M[][C] , bool vis[][C] , int row , int col){
    if(M[row][col] && !vis[row][col] && row>0 && row<R && col>0 && col<C){
        return true;
    }
    return false;
}
void bfs(int M[][C], int i , int j , int x , int y){
    bool vis [R][C];
    memset(vis , false , sizeof(vis));
    queue<node> q ;
    vis[i][j] = true;
    q.push({i,j,0});
    int min_dist= INT_MAX;
    while(!q.empty()){
        node Node = q.front();
        q.pop();
        int i= Node.x , j=Node.y ,dist = Node.dist;
        if(i==x && j==y){
            min_dist= dist;
            break;
        }
        for(int  k =0 ; k<4;k++){
            if(isvalid(M,vis,i+row[k],j+col[k])){
                vis[i+row[k]][j+col[k]]=true;
                q.push({ i + row[k], j + col[k], dist + 1 });
                
            }
        }
    }
    if(min_dist != INT_MAX){
        cout<<min_dist;
    }
    else{
        cout<<0;
    }
}
int main() {
	int mat[R][C]={
	    { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};
	bfs(mat,0,0,7,5) ;// (7,5) is our destination
	return 0;
}