# Searching Algorithms

| Algorithm            | Best | Average      | Worst  | Space | Requires Sorted |
|----------------------|------|--------------|--------|-------|-----------------|
| Linear Search        | O(1) | O(n)         | O(n)   | O(1)  | No              |
| Binary Search        | O(1) | O(log n)     | O(log n) | O(1) | Yes            |
| Jump Search          | O(1) | O(√n)        | O(√n)  | O(1)  | Yes             |
| Interpolation Search | O(1) | O(log log n) | O(n)   | O(1)  | Yes (uniform)   |
| Exponential Search   | O(1) | O(log n)     | O(log n) | O(1) | Yes            |

Reference: [GeeksForGeeks — Searching Algorithms](https://www.geeksforgeeks.org/searching-algorithms/?ref=ghm)

---

## Linear Search

Scans each element sequentially until the target is found or the array ends.

```mermaid
flowchart LR
    A["1 3 5 7 9<br/>target=7"] -->|"1? No"| B["3? No"]
    B -->|"3? No"| C["5? No"]
    C -->|"5? No"| D["7? Yes"]
```

- Time: O(n) — Space: O(1)
- Works on unsorted data

---

## Binary Search

Repeatedly halves the search range by comparing the target to the middle element. Array must be sorted.

```mermaid
flowchart TD
    A["1 3 5 7 9 11 13<br/>target=11"] -->|"mid=7, 11 > 7"| B["9 11 13"]
    B -->|"mid=11, found"| C["return index 5"]
```

- Time: O(log n) — Space: O(1)
- Derivation: after k steps, 1 element remains → k = log(n)
- Can be implemented recursively or iteratively

---

## Jump Search

Jumps ahead by a fixed block size √n, then does a linear scan backwards once the target range is found.

```mermaid
flowchart LR
    A["1 3 5 7 9 11 13 15<br/>target=11, step=3"] -->|"arr[3]=7 < 11, jump"| B["arr[6]=13 > 11"]
    B -->|"linear scan back"| C["arr[5]=11, found"]
```

- Time: O(√n) — Space: O(1)
- Optimal block size: √n minimises total steps (n/m + m−1)

---

## Interpolation Search

Estimates the probe position using the value distribution, similar to how humans search a phonebook.

```mermaid
flowchart TD
    A["sorted uniform array<br/>target=7"] -->|"probe = lo + (target-arr[lo]) * (hi-lo) / (arr[hi]-arr[lo])"| B["check arr[probe]"]
    B -->|"arr[probe] < target"| C["search right"]
    B -->|"arr[probe] > target"| D["search left"]
    B -->|"arr[probe] = target"| E["found"]
```

- Best/avg: O(log log n) on uniformly distributed data
- Worst: O(n) when data is heavily skewed

---

## Exponential Search

Finds the range where the target may exist by doubling the index, then runs binary search within that range. Useful for unbounded or infinite arrays.

```mermaid
flowchart LR
    A["target=11"] -->|"arr[1]=3 < 11"| B["arr[2]=5 < 11"]
    B -->|"arr[4]=9 < 11"| C["arr[8]=15 > 11"]
    C -->|"binary search [4..8]"| D["found at index 5"]
```

- Time: O(log n) — Space: O(1)
- Particularly useful when the array is unbounded (size unknown)
