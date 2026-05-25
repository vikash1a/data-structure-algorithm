#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0; i<=n-1; i++){
            parent[i] = i;
        }
    }
    // path compression
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]+=1;
        }
    }

    bool isConnected(int u, int v){
        return find(u) == find(v);
    }
};

int main(){
    DisjointSet ds(5);
    ds.unionSets(0,1);
    ds.unionSets(2,3);
    ds.unionSets(3,4);

    cout<<"0, 1 "<<ds.isConnected(0,1)<<endl;
    cout<<"2, 3 "<<ds.isConnected(2,3)<<endl;
    cout<<"3, 4 "<<ds.isConnected(3,4)<<endl;
    cout<<"2, 4 "<<ds.isConnected(2,4)<<endl;
    cout<<"0, 4 "<<ds.isConnected(0,4)<<endl;
}