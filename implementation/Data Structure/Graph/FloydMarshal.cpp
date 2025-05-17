#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;  // A large number representing infinity

// TC - O(n^3), SC - O(n^2)
void floydWarshall(vector<vector<int>>& distV, int V){
    for(int i=0;i<=V-1;i++){
        for(int j=i+1;j<=V-1;j++){
            for(int k=i+1;k<=j-1;k++){
                distV[i][j] = min(distV[i][j], distV[i][k]+distV[k][j]);
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist, V);

    cout << "Shortest distances between every pair:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
