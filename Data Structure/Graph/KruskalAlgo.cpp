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
            parent[pu] = parent[pv];
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = parent[pu];
        }
        else{
            parent[pv] = parent[pu];
            rank[pv]+=1;
        }
    }

    bool isConnected(int u, int v){
        return find(u) == find(v);
    }
};

int kruskalAlgo(vector<vector<pair<int,int>>> adj, int v)
{
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0;i<=(int)adj.size()-1;i++){
        for(int j=0;j<=(int)adj[i].size()-1; j++){
            edges.push_back({adj[i][j].second,{i, adj[i][j].first}});
        }
        
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(v);
    int mstWeight = 0;
    for(auto it: edges){
        int w = it.first, u = it.second.first, v = it.second.second;
        if(!ds.isConnected(u,v)){
            mstWeight += w;
            ds.unionSets(u,v);
        }
    }
    return mstWeight;
}

int main(){
   vector<vector<pair<int,int>>> adjV;
    adjV.push_back({{1,2},{3,1},{4,4}});
    adjV.push_back({{0,2},{2,3},{5,7}});
    adjV.push_back({{1,3},{3,5},{5,8}});
    adjV.push_back({{0,1},{2,5},{4,9}});
    adjV.push_back({{0,4},{3,9}});
    adjV.push_back({{1,7},{2,8}});

    auto result = kruskalAlgo(adjV, 10);
    cout<<result<<endl;
    return 0;
}