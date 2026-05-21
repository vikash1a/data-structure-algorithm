# Heap

Complete binary tree. Max-heap: parent ≥ children. Min-heap: parent ≤ children.

| Operation | Time     |
|-----------|----------|
| Peek      | O(1)     |
| Insert    | O(log n) |
| Delete    | O(log n) |
| Heapify   | O(n)     |
| Search    | O(n)     |

```mermaid
flowchart TD
    subgraph before["Before Heapify: 3 1 2 4"]
        A1((3)) --> B1((1)) & C1((2))
        B1 --> D1((4))
    end
    subgraph after["Max-Heap: 4 3 2 1"]
        A2((4)) --> B2((3)) & C2((2))
        B2 --> D2((1))
    end
    before -->|"heapify"| after
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
