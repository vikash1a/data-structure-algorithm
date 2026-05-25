#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v){
    for(int k: v){
        cout<<k<<" ";
    }
    cout<<endl;
}
void heapifyHelper(vector<int>& v, int i, int n){
    int l = 2*i+1, r = 2*i+2;
    int largest = i;
    if(l<=n && (v[largest]<v[l])){
        largest = l;
    }
    if(r<=n && (v[largest]<v[r])) {
        largest = r;
    }
    if(largest!=i){
        swap(v[i],v[largest]);
        heapifyHelper(v,largest,n);
    }
    return;
}
void heapify(vector<int>& v){
    int n = v.size()-1;
    for(int i=n/2; i>=0; i--){
        heapifyHelper(v,i,n);
        print(v);
    }
}

int main(){
    cout<<"hello world"<<endl;
    // vector<int> v = {4,2,6,3,7,5,4,32,5};
    vector<int> v = {3,1,2,4};
    heapify(v);
    // print(v);
    return 0;
}