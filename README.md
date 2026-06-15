# Data Structures & Algorithms

## Resources

[github.com/ashishps1/awesome-leetcode-resources](https://github.com/ashishps1/awesome-leetcode-resources)

## Structure

```text
.
├── theory/                  # Notes and explanations by topic
│   ├── 01-searching/
│   │   └── 01-search-algo.md
│   ├── 02-sorting/
│   │   └── 01-sort-algo.md
│   ├── 03-data-structures-1/
│   │   ├── 01-data-structure.md
│   │   └── 02-heap.md
│   ├── 04-data-structures-2/
│   │   ├── 01-tree.md
│   │   ├── 02-binary-search-tree.md
│   │   ├── 03-graph/
│   │   │   ├── 01-graph.md
│   │   │   ├── 02-cycle-detection.md
│   │   │   ├── 03-topological-sort.md
│   │   │   ├── 04-shortest-path.md
│   │   │   ├── 05-mst.md
│   │   │   └── 06-kahns-algorithm.md
│   │   └── 04-trie.md
│   ├── 05-algo-1/
│   │   ├── 01-backtracking.md
│   │   ├── 02-greedy.md
│   │   └── 03-dp.md
│   ├── 06-algo-2/
│   │   ├── 01-bit-manipulation.md
│   │   ├── 02-moore-voting-algo.md
│   │   └── 03-kadane-algo.md
│   ├── 07-patterns/
│   │   └── 01-patterns.md
│   ├── 08-other/
│   │   ├── 01-cpp-stl.md
│   │   └── 02-other-notes.md
│   └── media/               # Images referenced by notes
│
├── problems/                # Practice problems by topic
│   ├── data-structure/      # C++ implementations by topic
│   │   ├── binary-search.cpp
│   │   ├── bit-manipulation.cpp
│   │   ├── heap.cpp
│   │   ├── linked-list.cpp
│   │   ├── stack.cpp
│   │   ├── trie.cpp
│   │   ├── graph/           # dijkstra, kruskal, prims, floyd-marshall, etc.
│   │   ├── sorting/         # merge-sort, quick-sort, heap-sort
│   │   └── tree/            # binary-tree, bst
│   ├── greedy/
│   │   └── n-meeting-in-1-room/
│   └── lists/               # Problem tracking lists
│       ├── leetcode-top-150.md
│       └── pattern-problem-list.md
│
└── scratch/                 # Throwaway experiments
    └── playground.cpp
```

## How to run a cpp file

```bash
g++ scratch/playground.cpp -o scratch/playground && ./scratch/playground
```

Or for any implementation file:

```bash
g++ problems/data-structure/graph/dijkstra.cpp -o /tmp/dijkstra && /tmp/dijkstra
```
