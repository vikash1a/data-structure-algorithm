# Data Structures & Algorithms

## Resources
[github.com/ashishps1/awesome-leetcode-resources](https://github.com/ashishps1/awesome-leetcode-resources)

## Structure

```
.
├── implementation/          # C++ implementations by topic
│   ├── binary-search.cpp
│   ├── bit-manipulation.cpp
│   ├── heap.cpp
│   ├── linked-list.cpp
│   ├── stack.cpp
│   ├── trie.cpp
│   ├── graph/               # dijkstra, kruskal, prims, floyd-marshall, etc.
│   ├── sorting/             # merge-sort, quick-sort, heap-sort
│   └── tree/                # binary-tree, bst
│
├── theory/                  # Notes and explanations by topic
│   ├── 01-searching/
│   │   └── 01-search-algo.md
│   ├── 02-sorting/
│   │   └── 01-sort-algo.md
│   ├── 03-data-structures-1/
│   │   └── 01-data-structure.md
│   ├── 04-data-structures-2/
│   │   ├── 01-tree.md
│   │   ├── 02-binary-search-tree.md
│   │   ├── 03-graph.md
│   │   └── 04-trie.md
│   ├── 05-algo-1/
│   │   ├── 01-backtracking.md
│   │   ├── 02-greedy.md
│   │   └── 03-dp.md
│   ├── 06-algo-2/
│   │   ├── 01-bit-manipulation.md
│   │   └── 02-moore-voting-algo.md
│   ├── 07-patterns/
│   │   └── 01-patterns.md
│   ├── 08-other/
│   │   ├── 01-cpp-stl.md
│   │   └── 02-other-notes.md
│   └── media/               # Images referenced by notes
│
├── problems/                # Practice problems by topic
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
g++ implementation/graph/dijkstra.cpp -o implementation/graph/dijkstra && ./implementation/graph/dijkstra
```

## To Do
- [ ] https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
- [ ] Sweeping Line Algorithm
- [ ] Kadane algo
- [ ] Practice c++ list stl

## Problem Solving Log
- [X] binary search in c++, lower_bound & upper_bound — [reference](https://leetcode.com/problems/most-profit-assigning-work/solutions/5328902/most-profit-assigning-work/)
