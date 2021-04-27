#include <iostream>
#include <climits>
using namespace std;
int C, M ,ANS;
void calculate(int i , int *OM , bool *vis , int minV , int maxV , int sum , int nodes , int &ANS){
    if(vis[i]){
        int newMin = min(sum , minV);
        int newMax = max(sum, maxV);
        if(nodes == C-1){
            ANS = min(ANS , newMax - newMin);
        }
        return;
    }
    vis[i] = 1;
    int j = (i+1)%M;
    calculate(j , OM , vis , minV , maxV , sum+OM[i] , nodes , ANS);
    int newMin = min(sum, minV);
    int newMax = max(sum , maxV);
    calculate(j , OM , vis ,newMin , newMax , OM[i] , nodes+1 , ANS);
    vis[i] = 0;
    return;
}
int main() {
	int t;
	cin>>t;
	int ctr = 1;
	while(t--){
	    cin>>C>>M;
	    
	    int *OM = new int[M+1];
	    bool *vis = new bool[M+1];
	    for(int i = 0 ; i<M ; i++){
	        cin>>OM[i];
	        vis[i] = 0;
	    }
	    ANS = INT_MAX;
	    for(int i = 0 ; i<M ; i++){
	        calculate(i , OM , vis , INT_MAX , INT_MIN , 0 , 0 , ANS);
	        
	    }
	    cout<<"#"<<ctr<<" "<<ANS<<endl;
	    ctr++;
	}
	return 0;
}
