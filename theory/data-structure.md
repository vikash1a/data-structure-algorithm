
# Data Structures

## Arrays
```
Pointers
    Int var = 10;
    Int *ptr = &var;
    Var -10, ptr - 100, *ptr  = 10;
```
```cpp
vector<int> v = vector<int>(10,0);
push_back(), pop_back()
v[1]
sort(v.begin(), v.end());
```

## Linked List
- STL
  - list<T> -> front(),back(),push_back(),push_front()
- Definition
```cpp
    class node{
        int val;
        node *next;
        Node(int x){
            Val = x; 
        }
    };
```
   
- Doubly linked list - Practice done
- Floyd Cycle Finding Algo 
    https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/

## String
- Find
  - s.find(string delim, start) => returns starting index of delim if not found returns -1
- SubString
  - string substr (size_t pos, size_t len) 

## Stack 
    Syntax   
        Stack <dt> st;  
        st.push(a),st.pop(),st.top(),st.size(),st.empty()  

    Design and Implementation  
        Implement queue using stack - sl  
            Enqueue or dequeu has to be o(n)  
        Design and Implement Special Stack Data Structure | Added Space Optimized Version - not important  
        Implement two stacks in an array  
            Create stack from extreme corners   
        Implement stack using queue  
            Push or pop has to be o(n)  

    Standard Problems on stack  
        Infix to postfix - check later  
        Stock span problem - sl, end  
        Balanced parentheses - sl, end  
        Next greater element - sl, end  

    Operation on stack  
    Reverse a stack using recursion

## Queues
    queue<dt>;  
    q.push(a),q.front(),q.back(),q.pop(),size,empty  
    Deque   
    Push_back, pop_back, push_front, pop_front

## Hashing
unordered_set, unordered_map
- insert, find, erase

## Maps  (map, set)
- Based on red lack tree (balanced binary tree)  
  - insert, find, erase
- Multiset - duplicate value can be stored
  
## Heaps
- Syntax  
   ```
   priority_queue<int> -max heap first element largest
   priority_queue<int,vector<int>, greater<int>,> - min heap, first element smallest 

   Push, pop,top,size,empty,swap  
   ```
- Heapify algo
- Custom comparator for priority queue 
```cpp
bool compare(int a, int b) {
    return a > b;  // for min-heap
}
std::priority_queue<
        int, 
        std::vector<int>, 
        std::function<bool(int, int)>
    > minHeap(compare);  // Pass the comparator function
```
- Can have duplicates
- Time complexity  
   Insert,delete - o(log(n)), peek - O(1)  
- Binary Heap  
    Complete binary tree - all position filled from left
- Max heapify Example
```
Max Heapify Process on [3, 1, 2, 4]

Initial Tree (Array: [3, 1, 2, 4])
----------------------------------
        3
       / \
      1   2
     /
    4

Step 1: Heapify at index 1 (Swap 1 with 4)
------------------------------------------
        3
       / \
     [4]  2
     /
[1]

Array: [3, 4, 2, 1]

Step 2: Heapify at index 0 (Swap 3 with 4)
------------------------------------------
       [4]
       / \
     [3]  2
     /
    1

Array: [4, 3, 2, 1]

Final Max Heap Tree (Array: [4, 3, 2, 1])
------------------------------------------
        4
       / \
      3   2
     /
    1

```
