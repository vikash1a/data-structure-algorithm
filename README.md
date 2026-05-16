# Data Structures & Algorithms

## Resources
[github.com/ashishps1/awesome-leetcode-resources](https://github.com/ashishps1/awesome-leetcode-resources)

## Structure

```
.
├── implementation/          # C++ implementations by topic
│   ├── binary-search/
│   ├── bit-manipulation/
│   ├── graph/               # graph, dijkstra, kruskal, prims, floyd-marshall, etc.
│   ├── heap/
│   ├── linked-list/
│   ├── sorting/             # merge-sort, quick-sort, heap-sort
│   ├── stack/
│   ├── tree/                # binary-tree, bst
│   └── trie/
│
├── theory/                  # Notes and explanations by topic
│   ├── backtracking.md
│   ├── binary-search-tree.md
│   ├── bit-manipulation.md
│   ├── cpp-stl.md
│   ├── data-structure.md
│   ├── dp.md
│   ├── graph.md
│   ├── greedy.md
│   ├── moore-voting-algo.md
│   ├── other-notes.md
│   ├── patterns.md
│   ├── search-algo.md
│   ├── sort-algo.md
│   ├── tree.md
│   ├── trie.md
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
