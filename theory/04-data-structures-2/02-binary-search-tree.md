# Binary Search Tree

A binary tree where for every node: all left subtree values < node < all right subtree values. No duplicates.

| Operation | Average  | Worst (skewed) |
|-----------|----------|----------------|
| Search    | O(log n) | O(n)           |
| Insert    | O(log n) | O(n)           |
| Delete    | O(log n) | O(n)           |

---

## Structure

```mermaid
flowchart TD
    A((8)) --> B((3)) & C((10))
    B --> D((1)) & E((6))
    E --> F((4)) & G((7))
    C --> H[null] & I((14))
    I --> J((13)) & K[null]
```

---

## Search

Compare target to current node — go left if smaller, right if larger.

```mermaid
flowchart LR
    A((8)) -->|"6 < 8, left"| B((3))
    B -->|"6 > 3, right"| C((6))
    C -->|"found"| D(["✓"])
```

---

## Insert

Follow search path until a null slot is found, insert there.

```mermaid
flowchart LR
    A((8)) -->|"5 < 8, left"| B((3))
    B -->|"5 > 3, right"| C((6))
    C -->|"5 < 6, left"| D((4))
    D -->|"5 > 4, right → null"| E(["insert 5"])
```

---

## Delete

Three cases depending on the node's children:

```mermaid
flowchart TD
    subgraph c1["Case 1: leaf node (13)"]
        a1((14)) --> b1((13)) & c1n[null]
        b1 -->|"remove"| d1[null]
    end
    subgraph c2["Case 2: one child (10)"]
        a2((8)) --> b2((10))
        b2 -->|"replace with child"| c2n((14))
    end
    subgraph c3["Case 3: two children (3)"]
        a3((8)) --> b3((3)) & x3((10))
        b3 --> c3l((1)) & c3r((6))
        c3r --> d3((4)) & e3((7))
        d3 -->|"inorder successor replaces 3"| f3(["4 replaces 3"])
    end
```

- **Case 1** — node is a leaf: simply remove it
- **Case 2** — node has one child: replace node with its child
- **Case 3** — node has two children: replace with **inorder successor** (smallest node in right subtree), then delete the successor

---

## BST vs Hash Table

| | BST | Hash Table |
|---|---|---|
| Search | O(log n) | O(1) avg |
| Range queries | O(log n + k) | O(n) |
| Sorted order | Yes (inorder) | No |
| Worst case | O(n) | O(n) |

BST is preferred for **range queries** and when **sorted order** is needed.

---

## Key Operations

- **Construct BST from preorder traversal** — use a stack or recursion with range checks
- **Sorted array → BST** — pick mid as root, recurse on left and right halves → O(n)
- **Sorted linked list → BST** — find mid via slow/fast pointers → O(n log n)
- **Lowest Common Ancestor** — if both nodes < root go left, both > root go right, else root is LCA
- **Convert to greater sum tree** — reverse inorder traversal (right → root → left), accumulate sum
