# Minimum Spanning Tree

A **spanning tree** connects all V vertices of a graph using exactly V−1 edges with no cycles. An **MST** is the spanning tree with the minimum total edge weight.

- Only defined for connected, weighted, undirected graphs
- May not be unique if edge weights are equal
- V vertices → exactly V−1 edges in the MST

```mermaid
flowchart LR
    A((A)) -->|"1"| B((B))
    A -->|"3"| C((C))
    B -->|"1"| D((D))
    C -->|"2"| D
    B -->|"4"| C
```

**MST edges:** A-B(1), B-D(1), C-D(2) → total weight: **4**

---

## Prim's Algorithm

Grows the MST one vertex at a time. Always picks the cheapest edge that connects the current MST to an unvisited vertex.

**Think of it as:** expanding a bubble — at each step, pick the cheapest way to add one more node to the bubble.

```mermaid
flowchart LR
    subgraph step1["Start at A — add cheapest edge"]
        a1((A)) -->|"1 ✓"| b1((B))
    end
    subgraph step2["From A,B — cheapest to outside"]
        a2((A)) -->|"1 ✓"| b2((B))
        b2 -->|"1 ✓"| d2((D))
    end
    subgraph step3["From A,B,D — cheapest to outside"]
        a3((A)) -->|"1 ✓"| b3((B))
        b3 -->|"1 ✓"| d3((D))
        d3 -->|"2 ✓"| c3((C))
    end
    step1 --> step2 --> step3
```

**Algorithm:**

```
visited = {src}
min-heap: push all edges from src with their weights

while heap not empty and MST has < V-1 edges:
    (w, u, v) = pop min
    if v already visited: skip
    add edge (u,v,w) to MST
    visited.add(v)
    push all edges from v to unvisited nodes into heap
```

**Time:** O(E log V) with a min-heap — **Space:** O(V+E)

---

## Kruskal's Algorithm

Builds the MST by sorting all edges and adding them greedily, skipping any edge that would form a cycle. Uses **Union-Find** to detect cycles efficiently.

**Think of it as:** picking globally cheapest edges one by one, connecting separate components.

```mermaid
flowchart LR
    subgraph sorted["Edges sorted by weight"]
        e1["A-B: 1"] --> e2["B-D: 1"] --> e3["C-D: 2"] --> e4["A-C: 3"] --> e5["B-C: 4"]
    end
    subgraph mst["MST built"]
        m1["Add A-B(1) ✓"] --> m2["Add B-D(1) ✓"] --> m3["Add C-D(2) ✓"] --> m4["A-C(3) skipped — cycle"]
    end
    sorted --> mst
```

**Algorithm:**

```
sort all edges by weight
MST = []

for each edge (u, v, w) in sorted order:
    if find(u) != find(v):     // different components, no cycle
        MST.add(edge)
        union(u, v)
    if len(MST) == V-1: break
```

**Time:** O(E log E) for sorting — **Space:** O(V)

---

## Union-Find (Disjoint Set Union)

Data structure used by Kruskal's to track which vertices are in the same component and detect cycles in near-constant time.

### Find — with path compression

Finds the root of the component. Path compression makes all nodes on the path point directly to the root, flattening the tree for future queries.

```mermaid
flowchart TD
    subgraph before["Before path compression"]
        r1((root)) --> a1((a)) --> b1((b)) --> c1((c))
    end
    subgraph after["After find(c) — path compression"]
        r2((root)) --> a2((a)) & b2((b)) & c2((c))
    end
    before -->|"find(c)"| after
```

```
find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])   // path compression
    return parent[x]
```

### Union — by rank

Attaches the shorter tree under the taller one to keep the structure flat.

```
union(x, y):
    px, py = find(x), find(y)
    if px == py: return            // already in same set
    if rank[px] < rank[py]: swap(px, py)
    parent[py] = px
    if rank[px] == rank[py]: rank[px]++
```

**Time:** O(α(n)) ≈ O(1) per operation — α is the inverse Ackermann function, effectively constant for all practical inputs.

---

## Prim's vs Kruskal's

| | Prim's | Kruskal's |
|---|---|---|
| Approach | Grow from a vertex | Sort edges globally |
| Best for | Dense graphs (many edges) | Sparse graphs (few edges) |
| Data structure | Min-heap | Union-Find + sorted edges |
| Time | O(E log V) | O(E log E) |
| Handles disconnected? | No (needs connected graph) | Yes (finds MST per component) |
