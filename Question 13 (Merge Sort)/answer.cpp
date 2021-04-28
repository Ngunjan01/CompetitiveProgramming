#include <iostream>
using namespace std;
#define lim 100
int over_nos[lim];
int k;
int num_pots;
void merger(int l , int m , int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1] , R[n2];
    for(int i = 0 ; i<n1 ; i++){
        L[i] = over_nos[l+i];
    }
    for(int j = 0 ; j<n2 ; j++){
        R[j] = over_nos[m+1+j];
    }
    i = 0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            over_nos[k] = L[i];
            i++;
        }
        else{
            over_nos[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        over_nos[k] = L[i];
        k++;
        i++;
    }
    while(j<n2){
        over_nos[k] = R[j];
        k++;
        j++;
    }
}
void merge_sort(int l , int r){
    if(l<r){
        int m = l+(r-1)/2;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merger(l , m  ,r);
    }
}
int main() {
	cin>>num_pots;
	for(int i = 0 ; i<num_pots ; i++){
	    int x;
	    cin>>x;
	    over_nos[i] = x;
	}
	cin>>k;
	merge_sort(0 , num_pots-1);
	for(int i = num_pots-1; i>0 ; i--){
	    over_nos[i] = max(0,over_nos[i]- over_nos[i-1]);
	}
	int total_stones = 0;
	for(int i = 0 ; i<k ; i++){
	    total_stones += (over_nos[i]*(num_pots-i));
	}
	cout<<total_stones<<endl;
	return 0;
}
