#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int parent;
    int child;
    int wieight;
};
struct compare{
    bool operator()(Edge& e1, Edge& e2){
        return e1.wieight>e2.wieight;
    }
};
vector<vector<int>> primsAlgo(vector<vector<pair<int,int>>> adjV){
    int na = adjV.size()-1;
    vector<bool> visited(na+1, false);
    vector<vector<int>> vv;
    priority_queue<Edge, vector<Edge>, compare> pq; // parent is not needed if we are just lokking for sum not the actual node 

    Edge edge;
    edge.child = 0; edge.parent = 0; edge.wieight = 0;    
    pq.push(edge);
    while(!pq.empty()){
        Edge top = pq.top();
        pq.pop();
        if(visited[top.child]) continue;
        visited[top.child] = true;
        vv.push_back({top.parent, top.child});
        int parent = top.child;
        for(int j = 0; j<= adjV[parent].size()-1; j++){
            int child = adjV[parent][j].first;
            int wt = adjV[parent][j].second;
            if(!visited[child]){
                pq.push({parent, child, wt});
            }
        }
    }
    return {vv.begin()+1, vv.end()};
}


int main(){
    vector<vector<pair<int,int>>> adjV;
    adjV.push_back({{1,2},{3,1},{4,4}});
    adjV.push_back({{0,2},{2,3},{5,7}});
    adjV.push_back({{1,3},{3,5},{5,8}});
    adjV.push_back({{0,1},{2,5},{4,9}});
    adjV.push_back({{0,4},{3,9}});
    adjV.push_back({{1,7},{2,8}});

    auto result = primsAlgo(adjV);

    return 0;
}