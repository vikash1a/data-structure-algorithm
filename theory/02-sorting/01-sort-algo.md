# Sorting Algo

| Algorithm      | Best       | Average    | Worst      | Space    | Stable |
|----------------|------------|------------|------------|----------|--------|
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | O(1)     | No     |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)     | Yes    |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n) | No     |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)     | No     |

## Selection sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning

```mermaid
flowchart LR
    A["5 3 1 4 2"] -->|"min=1, swap"| B["1 3 5 4 2"]
    B -->|"min=2, swap"| C["1 2 5 4 3"]
    C -->|"min=3, swap"| D["1 2 3 4 5"]
```

```c++
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  

    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  

        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}
```

## Bubble sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

```mermaid
flowchart LR
    A["5 3 1 4 2"] -->|"pass 1"| B["3 1 4 2 5"]
    B -->|"pass 2"| C["1 3 2 4 5"]
    C -->|"pass 3"| D["1 2 3 4 5"]
```

```c++
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)    
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}
```

## Insertion sort

The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

```mermaid
flowchart LR
    A["5 | 3 1 4 2"] -->|"insert 3"| B["3 5 | 1 4 2"]
    B -->|"insert 1"| C["1 3 5 | 4 2"]
    C -->|"insert 4"| D["1 3 4 5 | 2"]
    D -->|"insert 2"| E["1 2 3 4 5"]
```

Function to sort an array using insertion sort

```c++
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++)  
    {  
        key = arr[i];  
        j = i - 1;  

        / Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position /  
        while (j >= 0 && arr[j] > key)  
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
```

## Merge sort

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

Time Compexity - T(n) = 2T(n/2)+Theta(n) => O(nlogn) in all case\
Space complexity - o(n)\
[Sorting_Merge_Sort](https://docs.google.com/document/d/1AYbPXgcxxtZ5BUlXsdTIMrCs8uluWQ9NoVdXiWy7DPw/edit) Checkout Merge sort for linked list

## Quick Sort

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

Time complexity , t(n) = t(k)+t(n-k)+theta(n)\
Avg -nlogn , best - nlogn, worse- n2\
Pseudo code understood\
Implementation done

## Heap sort

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

* Do after understanding binary heap data structure

* Time complexity - nlogn

* Insert element in heap - logn

* Delete element ( only topmost can be removed) - logn

* Create heap - nlogn

* Heap sort

  * Create heap

  * Delete all element

* Heapify - O(n)

* <https://www.youtube.com/watch?v=HqPJF2L5h9U>

* Check insertion in heap - bottom up approach - done
