#include <bits/stdc++.h>
using namespace std;
//self
/*
int minDistance(vector<int> sptSet,vector<int> distance){
    int n = distance.size()-1;
    int temp = INT_MAX;
    int ans = 0;
    for(int i=0;i<=n;i++){
        auto it =  find(sptSet.begin(),sptSet.end(),i);
        if(it==sptSet.end()){
            if(distance[i] <= temp ){
                temp = distance[i];
                ans =i;
            }
        }
    }
    return ans;
}
void dijkstraUtil(vector<vector<int>> graph,vector<int> sptSet,vector<int>& distance){
    int n = graph.size()-1;
    if(sptSet.size()-1 == n)return;
    int m = minDistance(sptSet,distance);
    sptSet.push_back(m);
    for(int i=0;i<=n;i++){
        if(graph[m][i]!=0){
            distance[i] = min(distance[i], distance[m]+graph[m][i]);
        }
    }
    dijkstraUtil(graph,sptSet,distance);
    return;
}
void dijkstra(vector<vector<int>> graph, int k){
    int n = graph.size()-1;
    vector<int> sptSet;
    vector<int> distance(n+1,INT_MAX);
    distance[k]=0;
    dijkstraUtil(graph,sptSet,distance);
    cout<<" dijstra distamce -> \n";
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<distance[i]<<"\n";
    }
    return;
}
*/

// //gfg
// int minDistance(vector<int> distance,vector<bool> sptSet){
//     int n = distance.size()-1;
//     int temp = INT_MAX, ans =0;
//     for(int i=0;i<=n;i++){
//         if(!sptSet[i] && distance[i]<=temp){
//             temp = distance[i];
//             ans =i;
//         }
//     }
//     return ans;
// }
// void dijkstra(vector<vector<int>> graph, int k){
//     int n = graph.size()-1;
//     vector<int> distance(n+1,INT_MAX);
//     distance[k] = 0;
//     vector<bool> sptSet (n+1, false);
//     for(int count=0;count<=n-1;count++){
//         int m = minDistance(distance,sptSet);
//         sptSet[m] = true;
//         for(int i=0;i<=n;i++){
//             if(graph[m][i]!=0 && !sptSet[i]){
//                 distance[i] = min(distance[i], distance[m]+graph[m][i]);
//             }
//         }
//     }
//     cout<<" dijkstra distance -> \n";
//     for(int i=0;i<=n;i++){
//         cout<<i<<" "<<distance[i]<<"\n";
//     }
//     return;
// }

//dijkstra optimised
vector<int> dijkstraOptimised(vector<vector<pair<int, int>>>& adj, int s){
    int n = adj.size()-1;
    vector<int> distance(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    distance[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int u = it.second;
        for(int j=0; j<=(int)adj[u].size()-1;j++){
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            // cout<<u<<" "<<v<<" "<<w<<endl;
            if(distance[v] > distance[u]+w){
                distance[v] = distance[u]+w;
                pq.push({distance[u]+w, v});
            }
        }
    }
    return distance;
}
int main(){
    cout<<"Hello World\n";

    // vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    // dijkstra(graph, 0);

    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    // Add edges (u, v, weight)
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 8});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 2});
    adj[3].push_back({4, 7});
    adj[2].push_back({4, 5});

    
    vector<int> dist = dijkstra(adj, 0);

    // Output shortest distances from source 0
    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": " << dist[i] << "\n";
    }
 
    return 0;


}
