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

First, label each node with its in-degree:

```mermaid
flowchart LR
    A("5 [in:0]") --> C("2 [in:1]") & D("0 [in:2]")
    B("4 [in:0]") --> D & E("1 [in:3]")
    C --> E
    D --> E & F("3 [in:2]")
    E --> F
```

Nodes 5 and 4 have in-degree 0 — they go into the queue first.

| Step | Pop | Neighbours reduced | New in-degree 0? | Queue      | Result          |
|------|-----|--------------------|------------------|------------|-----------------|
| Init | —   | —                  | 5, 4             | [5, 4]     | []              |
| 1    | 5   | 2→0, 0→1           | 2                | [4, 2]     | [5]             |
| 2    | 4   | 0→0, 1→2           | 0                | [2, 0]     | [5, 4]          |
| 3    | 2   | 1→1                | —                | [0]        | [5, 4, 2]       |
| 4    | 0   | 1→0, 3→1           | 1                | [1]        | [5, 4, 2, 0]    |
| 5    | 1   | 3→0                | 3                | [3]        | [5, 4, 2, 0, 1] |
| 6    | 3   | —                  | —                | []         | [5, 4, 2, 0, 1, 3] |

count = 6 == V = 6 → **no cycle, valid topological order ✓**

```mermaid
flowchart LR
    A(["queue:[5,4]"]) -->|"pop 5, enqueue 2"| B(["queue:[4,2]"])
    B -->|"pop 4, enqueue 0"| C(["queue:[2,0]"])
    C -->|"pop 2"| D(["queue:[0]"])
    D -->|"pop 0, enqueue 1"| E(["queue:[1]"])
    E -->|"pop 1, enqueue 3"| F(["queue:[3]"])
    F -->|"pop 3"| G(["queue:[] ✓"])
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
