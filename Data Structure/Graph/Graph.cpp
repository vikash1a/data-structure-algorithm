#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        void test(){
            //bfs
            // vector<vector<int>> adj = createGraph();
            // vector<int> bfsV = bfs(adj);
            // print(bfsV);
            //

            //dfs
            // vector<vector<int>> adj = createGraph();
            // vector<int> dfsV = bfs(adj);
            // print(dfsV);
            //

            // //detect cycle in undirected graph
            // vector<vector<int>> vvg ;
            // vvg.push_back({1,2});
            // vvg.push_back({0,2});
            // vvg.push_back({0,1,3});
            // vvg.push_back({2});

           
            //detect cycle in directed graph
            vector<vector<int>> vvg ;
            vvg.push_back({1,2});
            vvg.push_back({2});
            vvg.push_back({0,3});
            vvg.push_back({3});

            bool result = detectCycleDirected(vvg);
            cout<<" cycle detected - "<<result<<endl;
            
            return ;
        }
        void print(vector<int> v){
            for(int i:v){
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        //create graph
        vector<vector<int>> createGraph(){
            vector<vector<int>> vvg ;
            vvg.push_back({1,2});
            vvg.push_back({2});
            vvg.push_back({0,3});
            vvg.push_back({3});
            return vvg;
        }
        //

        //bfs
        vector<int> bfs(vector<vector<int>> adj){
            vector<int> bfsV;
            vector<int> visited(adj.size(),false);
            queue<int> qu;
            qu.push(0);
            visited[0]=true;
            while(!qu.empty()){
                int temp = qu.front();
                bfsV.push_back(temp);
                qu.pop();
                for(int i=0;i<=adj[temp].size()-1;i++){
                    if(!visited[adj[temp][i]]){
                        qu.push(adj[temp][i]);
                        visited[adj[temp][i]] = true;
                    }
                }
            }
            return bfsV;
        }

        //dfs
        vector<int> dfs(vector<vector<int>> adj){
            vector<int> dfsV;
            vector<int> visited(adj.size(),false);
            visited[0]=true;
            dfsHelper(adj,0,visited,dfsV);
            return dfsV; 
        }
        void dfsHelper(vector<vector<int>> adj, int k,vector<int> visited,vector<int>& dfsV){
            for(int i=0;i<=adj[k].size()-1;i++){
                if(!visited[adj[k][i]]){
                    visited[adj[k][i]] = true;
                    dfsV.push_back(adj[k][i]);
                    dfsHelper(adj,adj[k][i],visited,dfsV);
                }
            }
            return;
        }
        //

        //detect cycle in undirected graph
        bool detectCycle(vector<vector<int>> adj){
            int na = adj.size()-1;
            vector<bool> visited(na+1,false);
            for(int i=0;i<=na;i++){
                if(!visited[i]){
                    visited[i]=true;
                    if(detectCycleUtil(adj,i,-1,visited))return true;
                    visited[i]=false;
                    // cout<<i<<"-"<<endl;
                }
                
            }
            return false;
        }
        bool detectCycleUtil(vector<vector<int>> adj, int k,int parent, vector<bool> visited){
            
            for(int i=0;i<=adj[k].size()-1;i++){
                // cout<<parent<<"_"<<"_"<<k<<"_"<<i<<endl;
                int m = adj[k][i];
                if(!visited[m]){
                    visited[m]=true;
                    bool result = detectCycleUtil(adj,m,k,visited);
                    if(result)return true;
                }
                else if(m != parent)return true;
            }
            return false;
        }
        //

        //detect cycle in directed graph
        //tc - o(v+e), sc - O(v)
        bool detectCycleDirected(vector<vector<int>> adj){
            int na = adj.size()-1;
            vector<bool> visited(na+1, false);
            vector<bool> recStack(na+1, false);
            for(int i=0;i<=na;i++){
               if(!visited[i] && detectCycleDirectedUtil(adj,i,visited,recStack)){
                   return true;
               }
            }
            return false;
        }
        bool detectCycleDirectedUtil(vector<vector<int>> adj,int k,vector<bool> &visited,vector<bool> recStack){
            if(!visited[k]){
                visited[k]=true;
                recStack[k]=true;
                for(int i=0;i<=adj[k].size()-1;i++){
                    int elem = adj[k][i];
                    if(!visited[elem]){
                        if(detectCycleDirectedUtil(adj,elem,visited,recStack))return true;
                    }
                    else{
                        if(recStack[elem])return true;
                    }
                }
            }
            recStack[k]=false;
            return false;
        }
        //

        //detect cycle in directed graph using BFS
        //tc - o(v+e), sc - O(v+e)
        bool detectCycleDirectedBfs(vector<vector<int>> adj){
            int nv = adj.size()-1;
            vector<int> inOrder(nv+1, 0);
            for(int i=0;i<=nv; i++){
                for(int j=0;j<=(int)vvg[i].size()-1; j++){
                    inOrder[vvg[i][j]]+=1;
                }
            }
            queue<int> qu;
            for(int i=0;i<=nv; i++){
                if(inOrder[i]==0)qu.push(i);
            }
            int processed = 0;
            while(!qu.empty()){
                int front = qu.front();
                qu.pop();
                processed++;
                for(int i=0;i<=(int)vvg[front].size()-1;i++){
                    inOrder[vvg[front][i]]--;
                    if(inOrder[vvg[front][i]] == 0)qu.push(vvg[front][i]);
                }
            }
            return processed != nv+1
        }



};

int main(){
    cout<<"Hello World\n";
    Graph graph;
    graph.test();
    return 0;
}