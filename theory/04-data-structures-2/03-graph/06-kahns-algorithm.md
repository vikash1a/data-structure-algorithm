# Kahn's Algorithm

A BFS-based algorithm that processes a graph by repeatedly removing nodes with no incoming edges (in-degree 0). Serves two purposes:

1. **Topological Sort** — produces a valid linear ordering of a DAG
2. **Cycle Detection** — if not all nodes are processed, a cycle exists

**Time:** O(V+E) — **Space:** O(V)

---

## Core Idea — In-Degree

**In-degree** of a node = number of edges pointing *into* it.

A node with in-degree 0 has no dependencies — it is safe to process immediately. After processing it, reduce the in-degree of its neighbours. If any neighbour hits 0, it becomes ready to process next.

```mermaid
flowchart LR
    A((5)) --> C((2)) & D((0))
    B((4)) --> D & E((1))
    C --> E
    D --> E & F((3))
    E --> F
```

**In-degrees:** `5→0, 4→0, 2→1, 0→2, 1→3, 3→2`

---

## Step-by-Step Trace

```mermaid
flowchart TD
    s1["In-degrees\n5:0  4:0  2:1  0:2  1:3  3:2\nEnqueue: [5, 4]"]
    s2["Process 5 → reduce 2,0\n2:0  0:1  → enqueue 2\nqueue:[4,2]  result:[5]"]
    s3["Process 4 → reduce 0,1\n0:0  1:2  → enqueue 0\nqueue:[2,0]  result:[5,4]"]
    s4["Process 2 → reduce 1\n1:1\nqueue:[0]  result:[5,4,2]"]
    s5["Process 0 → reduce 1,3\n1:0  3:1  → enqueue 1\nqueue:[1]  result:[5,4,2,0]"]
    s6["Process 1 → reduce 3\n3:0  → enqueue 3\nqueue:[3]  result:[5,4,2,0,1]"]
    s7["Process 3\nqueue:[]  result:[5,4,2,0,1,3]"]
    s8(["count=6 == V=6\nNo cycle. Order: 5 4 2 0 1 3 ✓"])
    s1 --> s2 --> s3 --> s4 --> s5 --> s6 --> s7 --> s8
    style s8 fill:#9f9
```

---

## Cycle Detection

If a cycle exists, nodes in the cycle always have in-degree ≥ 1 — they point at each other and never get enqueued. The processed count ends up less than V.

```mermaid
flowchart LR
    G0((0)) --> G1((1))
    G1 --> G2((2))
    G2 --> G3((3))
    G3 --> G1
    style G1 fill:#f96
    style G2 fill:#f96
    style G3 fill:#f96
```

```mermaid
flowchart TD
    c1["In-degrees: 0→0  1→2  2→1  3→1\nEnqueue: [0]"]
    c2["Process 0 → reduce 1\n1:1  queue:[]  count=1"]
    c3["Queue empty\ncount=1 < V=4"]
    c4(["Cycle detected ✓\n1,2,3 stuck — in-degree never reached 0"])
    c1 --> c2 --> c3 --> c4
    style c4 fill:#f96
```

---

## Implementation

```cpp
vector<int> kahnSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            inDegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0) q.push(i);

    vector<int> result;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);
        for (int neighbour : adj[node])
            if (--inDegree[neighbour] == 0)
                q.push(neighbour);
    }

    if (result.size() < V) return {};   // cycle detected
    return result;
}
```

---

## Summary

| Use Case | What to check |
|---|---|
| Topological sort | Return `result` — valid order if `size == V` |
| Cycle detection | `result.size() < V` → cycle exists |
| Both at once | Run once, check size, use result |
