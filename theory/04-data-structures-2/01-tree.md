# Tree

A non-linear hierarchical data structure where each node has at most two children (binary tree).

| Property               | Value                  |
|------------------------|------------------------|
| Min height             | log(n+1)               |
| Max nodes at level l   | 2^l                    |
| Max nodes (height h)   | 2^h - 1                |
| Edges                  | n - 1                  |

---

## Structure

```mermaid
flowchart TD
    A((1)) --> B((2)) & C((3))
    B --> D((4)) & E((5))
    C --> F((6)) & G((7))
```

---

## Traversals

### DFS — O(n) time, O(h) space

| Order     | Pattern                  | Result on tree above |
|-----------|--------------------------|----------------------|
| Inorder   | Left → Root → Right      | 4 2 5 1 6 3 7        |
| Preorder  | Root → Left → Right      | 1 2 4 5 3 6 7        |
| Postorder | Left → Right → Root      | 4 5 2 6 7 3 1        |

```mermaid
flowchart LR
    in["Inorder"] --- i1((4)) --- i2((2)) --- i3((5)) --- i4((1)) --- i5((6)) --- i6((3)) --- i7((7))
    pre["Preorder"] --- r1((1)) --- r2((2)) --- r3((4)) --- r4((5)) --- r5((3)) --- r6((6)) --- r7((7))
    post["Postorder"] --- p1((4)) --- p2((5)) --- p3((2)) --- p4((6)) --- p5((7)) --- p6((3)) --- p7((1))
```

**Morris Inorder** — O(n) time, O(1) space: threads the tree using null right pointers to avoid a stack.

### BFS / Level Order — O(n) time, O(n) space

Uses a queue. Visits nodes level by level: `1 → 2 3 → 4 5 6 7`

---

## Tree Types

```mermaid
flowchart TD
    subgraph full["Full: 0 or 2 children"]
        fa((1)) --> fb((2)) & fc((3))
        fb --> fd((4)) & fe((5))
    end
    subgraph complete["Complete: filled left to right"]
        ca((1)) --> cb((2)) & cc((3))
        cb --> cd((4)) & ce((5))
        cc --> cf((6))
    end
    subgraph perfect["Perfect: all leaves same level"]
        pa((1)) --> pb((2)) & pc((3))
        pb --> pd((4)) & pe((5))
        pc --> pf((6)) & pg((7))
    end
    subgraph degen["Degenerate: each node one child"]
        da((1)) --> db((2))
        db --> dc((3))
        dc --> dd((4))
    end
```

- **Balanced** — height = O(log n), e.g. AVL, Red-Black Tree
- **Degenerate** — degrades to a linked list, O(n) operations

---

## Properties

- In a full binary tree, leaf nodes = internal nodes + 1
- Nth Catalan number gives count of structurally unique BSTs with n nodes:
  `T(n) = Σ T(i) * T(n-i-1)` for i = 0..n-1

---

## Key Operations

- **Insert** — BFS until a node with an empty child slot is found, insert there
- **Delete** — replace with inorder successor or deepest rightmost node
- **Inorder without recursion** — use an explicit stack
- **Inorder without recursion or stack** — Morris traversal
- **Reconstruct tree** — from inorder + preorder, or inorder + postorder
