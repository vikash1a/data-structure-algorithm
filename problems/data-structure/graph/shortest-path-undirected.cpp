#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> shortestPath(vector<vector<int>> adj, int n, int source, int destination){
    vector<int> path;
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> qu;
    qu.push(source);
    parent[source] = -1;
    visited[source] = true;
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();
        if(front == destination) break;
        for(int j=0;j<=adj[front].size()-1;j++){
            if(!visited[adj[front][j]]){
                visited[adj[front][j]] = true;
                parent[adj[front][j]] = front;
                qu.push(adj[front][j]);
            }
        }
    }
    for(int i=destination; i!=-1;i=parent[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Example graph with nodes 0 to 6
    vector<vector<int>> adjList = {
        {},         // node 0 (not used)
        {2, 3},     // node 1
        {1, 4},     // node 2
        {1, 5},     // node 3
        {2, 5},     // node 4
        {3, 4, 6},  // node 5
        {5}         // node 6
    };

    int start = 1;
    int end = 6;

    vector<int> path = shortestPath(adjList,7, start, end);

    if (!path.empty()) {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << end << "." << endl;
    }

    return 0;
}
