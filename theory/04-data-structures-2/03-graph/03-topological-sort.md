# Topological Sort

A linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every edge u→v, u appears before v. Not possible if the graph has a cycle.

```mermaid
flowchart LR
    A((5)) --> C((2)) & D((0))
    B((4)) --> D & E((1))
    C --> E
    D --> E & F((3))
    E --> F
```

**One valid order:** 5 → 4 → 2 → 0 → 1 → 3

**Use cases:** build systems, task scheduling, course prerequisites, dependency resolution.

---

## DFS + Stack

The key insight: a node should appear in the output only after all nodes reachable from it are processed. DFS naturally finishes the deepest nodes first — push to a stack on return, then pop the stack for the final order.

```mermaid
flowchart TD
    subgraph step1["DFS finishes 3 first — push 3"]
        s1(["stack: [3]"])
    end
    subgraph step2["DFS finishes 1 — push 1"]
        s2(["stack: [3, 1]"])
    end
    subgraph step3["DFS finishes 0 — push 0"]
        s3(["stack: [3, 1, 0]"])
    end
    subgraph step4["Continue until all pushed"]
        s4(["stack: [3, 1, 0, 2, 4, 5]"])
    end
    step1 --> step2 --> step3 --> step4
```

**Algorithm:**

```
topo_sort():
    visited = {}
    stack = []

    dfs(node):
        visited[node] = true
        for each neighbour in adj[node]:
            if not visited[neighbour]:
                dfs(neighbour)
        stack.push(node)          // push after all descendants processed

    for each unvisited node:
        dfs(node)

    return stack reversed         // or pop stack for order
```

**Time:** O(V+E) — **Space:** O(V)

---

## BFS — Kahn's Algorithm

Works by repeatedly removing nodes with no incoming edges (in-degree 0). This simulates "what can be done first when nothing depends on it."

```mermaid
flowchart LR
    A["In-degrees: 5→0, 4→0, 2→1, 0→2, 1→2, 3→2"] -->|"enqueue 5,4"| B["process 5: reduce 2,0"]
    B -->|"2 in-degree=0, enqueue"| C["process 4: reduce 0,1"]
    C -->|"process 2,0,1..."| D["order: 5 4 2 0 1 3"]
```

**Algorithm:**

```
compute in-degree for every node
enqueue all nodes with in-degree 0
result = []

while queue not empty:
    node = dequeue
    result.append(node)
    for each neighbour of node:
        in-degree[neighbour] -= 1
        if in-degree[neighbour] == 0:
            enqueue(neighbour)

if len(result) < V: cycle detected (not a DAG)
return result
```

**Time:** O(V+E) — **Space:** O(V)

---

## DFS vs Kahn's

| | DFS + Stack | Kahn's BFS |
|---|---|---|
| Approach | post-order push | in-degree peeling |
| Cycle detection | needs separate recStack | built-in (count < V) |
| Output order | reverse finish time | front-to-back naturally |
| Preferred when | recursive DFS is natural | cycle detection needed too |
