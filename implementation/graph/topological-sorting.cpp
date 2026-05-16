#include <bits/stdc++.h>
using namespace std;

//gfg using BFS
vector<int> topologicalSortBfs(vector<vector<int>> vvg, int nv){
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
    vector<int> topologicalOrder;
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();
        topologicalOrder.push_back(front);
        for(int i=0;i<=(int)vvg[front].size()-1;i++){
            inOrder[vvg[front][i]]--;
            if(inOrder[vvg[front][i]] == 0)qu.push(vvg[front][i]);
        }
    }
    return topologicalOrder;
}

//gfg using DFS

void topologicalSortUtil(vector<vector<int>> vvg, vector<bool>& visited,stack<int>& st,int k){
    visited[k] = true;
    if(vvg[k].size() >=1 ){
        for(int i=0;i<=vvg[k].size()-1;i++){
            if(!visited[vvg[k][i]]){
                topologicalSortUtil(vvg,visited,st,vvg[k][i]);
            }
        }
    }
    
    st.push(k);
    return;
}
vector<int> topologicalSort(vector<vector<int>> vvg, int nv){
    vector<bool> visited(nv+1,false);
    stack<int> st;

    for(int i=0;i<=nv;i++){
        if(!visited[i]){
            topologicalSortUtil(vvg, visited, st,i);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    cout<<"Hello World\n";

    vector<vector<int>> vvg;
    vvg.push_back({});
    vvg.push_back({});
    vvg.push_back({3});
    vvg.push_back({1});
    vvg.push_back({0,1});
    vvg.push_back({0,2});

    vector<int> v = topologicalSortBfs(vvg,5);
    cout<<"topological Sorting :-\n";
    for(int i:v){
        cout<<i<<" ";
    }

    return 0;
}
