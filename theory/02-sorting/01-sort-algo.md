# Sorting Algorithms

| Algorithm      | Best       | Average    | Worst      | Space    | Stable |
|----------------|------------|------------|------------|----------|--------|
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | O(1)     | No     |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)     | Yes    |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n) | No     |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)     | No     |

## Selection Sort

Repeatedly finds the minimum element from the unsorted portion and swaps it to the front.

```mermaid
flowchart LR
    A["5 3 1 4 2"] -->|"min=1, swap"| B["1 3 5 4 2"]
    B -->|"min=2, swap"| C["1 2 5 4 3"]
    C -->|"min=3, swap"| D["1 2 3 4 5"]
```

```c++
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
```

## Bubble Sort

Repeatedly swaps adjacent elements that are in the wrong order, bubbling the largest to the end each pass.

```mermaid
flowchart LR
    A["5 3 1 4 2"] -->|"pass 1"| B["3 1 4 2 5"]
    B -->|"pass 2"| C["1 3 2 4 5"]
    C -->|"pass 3"| D["1 2 3 4 5"]
```

```c++
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
```

## Insertion Sort

Builds a sorted prefix one element at a time by inserting each new element into its correct position.

```mermaid
flowchart LR
    A["5 | 3 1 4 2"] -->|"insert 3"| B["3 5 | 1 4 2"]
    B -->|"insert 1"| C["1 3 5 | 4 2"]
    C -->|"insert 4"| D["1 3 4 5 | 2"]
    D -->|"insert 2"| E["1 2 3 4 5"]
```

```c++
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

## Merge Sort

Divide and conquer — recursively splits the array in half, sorts each half, then merges them.

```mermaid
flowchart TD
    A["5 3 1 4 2"] --> B["5 3 1"]
    A --> C["4 2"]
    B --> D["5"]
    B --> E["3 1"]
    E --> Ea["3"]
    E --> Eb["1"]
    C --> Cf["4"]
    C --> Cg["2"]
    Ea --> H["1 3"]
    Eb --> H
    D --> I["1 3 5"]
    H --> I
    Cf --> J["2 4"]
    Cg --> J
    I --> K["1 2 3 4 5"]
    J --> K
```

- Time complexity: T(n) = 2T(n/2) + O(n) → O(n log n) in all cases
- Space complexity: O(n)
- [Merge Sort for Linked List](https://docs.google.com/document/d/1AYbPXgcxxtZ5BUlXsdTIMrCs8uluWQ9NoVdXiWy7DPw/edit)

## Quick Sort

Picks a pivot, partitions elements into less-than and greater-than groups, then recurses on each side.

```mermaid
flowchart TD
    A["5 3 1 4 2"] -->|"pivot=2"| B["left: 1"]
    A -->|"pivot=2"| P1["2"]
    A -->|"pivot=2"| C["right: 5 3 4"]
    C -->|"pivot=4"| D["left: 3"]
    C -->|"pivot=4"| P2["4"]
    C -->|"pivot=4"| E["right: 5"]
    B --> R["1 2 3 4 5"]
    P1 --> R
    D --> R
    P2 --> R
    E --> R
```

- Time complexity: T(n) = T(k) + T(n-k) + O(n)
- Best/avg: O(n log n) — Worst: O(n²) when pivot is always min/max

## Heap Sort

Builds a max-heap from the array, then repeatedly extracts the maximum to produce a sorted result.

```mermaid
flowchart TD
    subgraph heap["Step 1 - Build Max-Heap"]
        R((5)) --> L((4))
        R --> Ri((3))
        L --> Ll((2))
        L --> Lr((1))
    end
    subgraph extract["Step 2 - Extract Max"]
        e1["extract 5"] --> e2["extract 4"] --> e3["extract 3"] --> e4["1 2 3 4 5"]
    end
    heap --> extract
```

- Heapify: O(n)
- Insert / delete: O(log n)
- Overall: O(n log n) in all cases, O(1) space
- [Video reference](https://www.youtube.com/watch?v=HqPJF2L5h9U)
