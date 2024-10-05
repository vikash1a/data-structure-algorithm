## Graph

### Representations 
- Adjacency list  
```

    {vertex}{edges}  
    0 -> 1,2  
    1-> 2  
    2 -> 0,3  
    3 -> 4   
```
- Adjacency matrix  

### BFS 
 - Tc- o(v+e), auxiliary space - O(v)  
  v1 + (incident edges) + v2 + (incident edges) + .... + vn + (incident edges)  
 - Handling disconnected graph  
  Just to modify BFS, perform simple BFS from each unvisited vertex of given graph.  


### DFS 
- Using recursion, same as tree  
- Pseudo code   
```
dfs(vector<vector<int>> v, vertex, visited){  
    for edge in vertex:  
        vertexTemp = edge-> vertex  
        if vertexTemp not visited:  
            print(vertexTemp)  
            visited[vertexTemp] = true;  
        dfs(v, vertexTemp, visited);  
}

Tc - O(v+e) sc - O(v)  
```
- Handling disconnected graph  
  Perform simple BFS from each unvisited vertex of given graph.

DFS Application  
- Cycle detection - direct , indirect  
- Path finding   
- Topological sorting   

BFS Application   
- Shortest path and minimum spanning tree for unweighted graph  

Other
- Representation using set and hash  
- Auxiliary space complexity vs space complexity  
  Auxiliary space complexity - Use by compute like function Stack  
  Space complexity = Auxiliary space complexity + Use by variable

### Cycle

Detect cycle in undirected graph  
#### Dfs and using visited  
```
Run a Depth First Traversal on the given subgraph connected to the current node and pass the parent of the current node. In each recursive   
  Set visited[root] as 1.  
  Iterate over all adjacent nodes of the current node in the adjacency list   
  If it is not visited then run DFS on that node and return true if it returns true.  
  Else if the adjacent node is visited and not the parent of the current node then return true.  
  Return false.  
```

#### BFS  
```
  Start BFS traversal from each unvisited node in the graph.  
  While traversing, mark each visited node.  
  If a node is encountered that is already marked as visited, it implies the presence of a cycle.  
  Continue BFS traversal until all nodes are visited or a cycle is detected.  
```
Detect cycle in directed graph  
#### Dfs using visited and recStack  
```
  Create a recursive dfs function that has the following parameters – current vertex, visited array, and recursion stack .

  Mark the current node as visited and also mark the index in the recursion stack. 

  Iterate a loop for all the vertices and for each vertex, call the recursive function if it is not yet visited (This step is done to make sure that if there is a forest of graphs, we are checking each forest): 

  In each recursion call, Find all the adjacent vertices of the current vertex which are not visited:  

  If an adjacent vertex is already marked in the recursion stack then return true .  

  Otherwise, call the recursive function for that adjacent vertex.  

  While returning from the recursion call, unmark the current node from the recursion stack, to represent that the current node is no longer a part of the path being traced.  

  If any of the functions returns true , stop the future function calls and return true as the answer.  
```

#### Using BFS - Skipped

### Topological sorting
#### Directed acyclic graph (DAGs)  
##### Using stack and visited, and dfs  
       Create a graph with n vertices and m-directed edges.  

       Initialize a stack and a visited array of size n.  
       For each unvisited vertex in the graph, do the following:  
         Call the DFS function with the vertex as the parameter.  
         In the DFS function, mark the vertex as visited and recursively call the DFS function for all unvisited neighbors of the vertex. 

       Once all the neighbors have been visited, push the vertex onto the stack.  

       After all, vertices have been visited, pop elements from the stack and append them to the output list until the stack is empty.  

       The resulting list is the topologically sorted order of the graph.  
##### Using BFS - Skipped

### Minimum Spanning tree
Definition  
- Graph - weighted and undirected and connected  
- Spanning Tree Definition -  Convert graph to tree with n vertices and n-1 edges and all nodes are reachable from each other  
- Minimum Spanning Tree Definition - Cumulative weight should be minimum  

Prim’s Algo   
Kruskal algo & Union Find ❎

### Backtracking
Find if there is a path of more than k length from a source   
Implementation pending ❎

### Shortest path
#### Dijkstra algo  
```
Tc - o(v^2)  
Work on both directed and undirected graph  
Does not work for negative edge  
Algo  
  Maintain a visited node and distance array  
  Select node with minimum distance from distance array which is not visited and update its neighbour distance if lesser  
  Do it V no of times as we want to visit all V vertex  
Optimisation  
  Use Priority queue for finding minimum distance  
  TC - O(Vlog(v))  
```
#### Bellman ford ❎  
```
DG - except negative cycle  
UG - only for positive number  
Algo  
  Initialize distance array  
  Do relaxation v-1 times  
    if(dist[u]+w<dist[v]) => dist[v] = dist[u]+w  
  TC - O(ve), sc- o(v)  
```
#### Floyd Marshal ❎  
```
To find shortest distance between every poor  
Tc- O(n^3)  
Revise algo
```

### Connectivity
- Find if there is a path between two vertices in a directed graph  
  Bfs or dfs   
#### Strongly connected graph (Kosaraju algo) ❎  
```
Stack of order dfs transversal  
Reverse all edge direction by taking transpose  
Do dfs again
```