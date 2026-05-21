# Heap

Complete binary tree. Max-heap: parent ≥ children. Min-heap: parent ≤ children.

| Operation | Time     |
|-----------|----------|
| Peek      | O(1)     |
| Insert    | O(log n) |
| Delete    | O(log n) |
| Heapify   | O(n)     |
| Search    | O(n)     |

**How it works:**
Start from the last non-leaf node (index `n/2 - 1`) and run **sift-down** towards the root. Sift-down compares a node with its children and swaps it with the largest child, repeating until the node is in the correct position. Processing bottom-up ensures every subtree is a valid heap before its parent is processed, achieving O(n) build time rather than O(n log n).

Build max-heap from `[3, 1, 2, 4, 5]` — start heapifying from the last non-leaf (index 1) up to root (index 0):

```mermaid
flowchart TD
    subgraph s0["Initial: 3 1 2 4 5"]
        a0((3)) --> a1((1)) & a2((2))
        a1 --> a3((4)) & a4((5))
    end
    subgraph s1["Step 1: heapify idx 1 — swap 1 with 5"]
        b0((3)) --> b1((5)) & b2((2))
        b1 --> b3((4)) & b4((1))
    end
    subgraph s2["Step 2: heapify idx 0 — swap 3 with 5"]
        c0((5)) --> c1((3)) & c2((2))
        c1 --> c3((4)) & c4((1))
    end
    subgraph s3["Step 3: sift 3 down — swap 3 with 4"]
        d0((5)) --> d1((4)) & d2((2))
        d1 --> d3((3)) & d4((1))
    end
    s0 --> s1 --> s2 --> s3
```

**STL:**

```cpp
priority_queue<int> maxH;                                // max-heap (default)
priority_queue<int, vector<int>, greater<int>> minH;     // min-heap

maxH.push(x);  maxH.pop();  maxH.top();
```

**Custom comparator:**

```cpp
auto cmp = [](int a, int b) { return a > b; };  // min-heap
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

- Supports duplicates
- Built on a complete binary tree stored as an array — node `i` has children at `2i+1` and `2i+2`
