
# Data Structures

## Arrays
    Pointers
        Int var = 10;
        Int *ptr = &var;
        Var -10, ptr - 100, *ptr  = 10;
## Linked List

    Stl - list -> front(),back(),push_back(),push_front()
    Definition 
    class node{
        int val;
        node *next;
        Node(int x){
            Val = x; 
            }
        }
    Doubly linked list
        Practice done
    Floyd Cycle Finding Algo 
        https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
## Strings

    Find
        String s
        s.find(string delim, start) => returns starting index of delim if not found returns -1
    SubString
        string substr (size_t pos, size_t len) 
## Stack 
    Syntax   
        Stack <dt> st;  
        st.push(a),st.pop(),st.top()st.size(),st.empty()  

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
Unorderd_set, Unorederd_map

## Maps  (map, set)
- Based on red lack tree ( balanced binary tree)  
- Multiset - duplicate value can be stored
  
## Heaps
- Syntax  
   ```
   priority_queue<int> -max heap first element largest
   priority_queue<int,vector<int>, greater<int>,> - min heap, first element smallest 

   Push, pop,top,size,empty,swap  
   ```
- Heapify 
- Custom comparator for priority queue  
- Can have duplicates
- Time complexity  
   Insert,delete - o(log(n)), peek - O(1)  
- Binary Heap  
    Complete binary tree - all position filled from left
