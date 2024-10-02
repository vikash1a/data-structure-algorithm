
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
## Stack ( mostly done)
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

 1. Unorderd_set, Unorederd_map
## Maps - map, set

 1. Based on red lack tree ( balanced binary tree)  
 2. Multiset - duplicate value can be stored
## Heaps

 1. Syntax  
    1. priority_queue<int> -max heap first element largest, priority_queue<int,vector<int>, greater<int>,> - min heap, first element smallest  
    2. Push, pop,top,size,empty,swap  
    3. Heapify - check later, logic understood , practice remaining - done  
    4. Custom comparator for priority queue  
 2. Time complexity  
    1.  Insert,delete - o(log(n)), peek - O(1)  
 3. Binary Heap  
    1. Complete binary tree - all position filled from left
## Binary Tree

 1. Minimum possible height - log(n+1)  
 2. Transversal  
    1. DFS - In,pre,post  
        Tc - O(N), AS - O(h)  
    2. BFS / Level order  
        TC- O(N), sc - o(n)  
    3. Morris inorder  
        O(n) sc- O(1)  
        ![image4](./media/image4.png)
 3. Introduction  
    1. Properties  
        Maximum number of nodes at level l is 2l;  
        Maximum no of nodes in binary tree of height h is 2h -1  
        Minimum height of binary tree with n node is log2(n+1)  
        Binary tree with l leaves has at least log2(l)+1 level  
        In Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children  
        No of edge = no of node -1, root has no edge 

    2. Type  
        Full binary tree - either 0 or 2 children  
        Complete binary tree - all levels completely filled except last level  
        Perfect binary tree - A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same leve  
        Balanced binary tree - if height = log(n)  
        Degenerate or (pathological tree) - tree where very internal node has one child  
    3. Handshaking Lemma and Interesting Tree Properties - skipped  
    4. Enumeration of tree   
        Nth catalan number - T(n)=sum_{i=0}^{n-1}T(i)T(n-i-1)  for  ngeq 1;                               
        Unlabeled tree - T(n) = (2n)! / (n+1)!n!  
        Labeled tree - T(n) = (2n)! / (n+1)!  
    5. Insert node  
        Bfs until we find node with either left or right child empty  
        Insert new node there  
    6. Delete node  
    7. BFS vs DFS  
        Time complexity  - O(n) n = no. of node  
        Space complexity  
          Dfs- o(height)  
          BFS - o (weight)  
    8. Binary tree, array implementation  
    9.  AVL with duplicate keys - check later  
 4. Traversals  
    1. Trasvaersals  
    2. Inorder without recursion , using stack - check later  
    3. Inorder without recursion and stack , morris traversal, check later  
    4. Create postorder from in and pre - sl  
    5. Create post order from preorder - sl  
    6. Find all possible binary tree with given inorder traversal - check later  
 5. Construction and conversion  
    1. Construct tree from inorder and preorder
## Binary Search Tree(gfg done)

  1. Properties  
     1. All left node smaller and right node greater than parent for each n  
     2. No duplicate nodes allowed  
  2. Basic  
     1. Search and Insertion	  
         Brute force  
     2. Delete   
         Simple if node has 0 or 1 node  
         If node has 2 node, replace with inorder successor  
     3. Advantage of BST over Hash  
         In range queries  
  3. Construction and Conversion  
     1. Convert bst from preorder transversal  
         Using stack  
         Using recursion, range - check later  
     2. Bst from binary tree  
         1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.  
         2) Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. In the following implementation, Quick Sort is used which takes (n^2) time. This can be done in O(nLogn) time using Heap Sort or Merge Sort.  
         3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step takes O(n) time.  
     3. Sorted Linked List to BST  
         Do in O(n)  
     4. Sorted Array to BST (easy implementation not done)  
     5. Transverse bst to grater sum tree (imp not done)  
         Use reverse order transversal  
  4. Checking and Searching  
     1. Minimum value in BST  
     2. Check if the given array can represent Level Order Traversal of Binary Search Tree check later  
     3. Check if a given array can represent Preorder Traversal of Binary Search Tree check later  
     4. Lowest common ancestor of two nodes in BST - sl learnt


## Bit Manipulation

1. Operator
   1. AND (&) ->  1 if both 1
   2. OR (|) ->1 if atleast 2
   3. XOR (^) -> 1 if only one 1
   4. NOT (~) -> Invert all bits
   5. Left Shift (<<) -> Shift bit to left , filling with zeros
   6. Right shift (>>) -> shift bit to right, filling with zeros

## Backtracking

1. Brute force approach for all possible combination
2. Used when greedy or dp does not work
3. TC - O(k^N) OR O(k!)
4. Pseudo Code
   ```void
       if (valid solution):  
       store the solution  
       Return  
       for (all choice):  
         if (valid choice):  
           APPLY (choice)  
           FIND_SOLUTIONS (parameters)  
           BACKTRACK (remove choice)  
       Return ```


   ```

## Greedy Algorithm

1. The steps to define a greedy algorithm are:
   1. Define the problem: Clearly state the problem to be solved and the objective to be optimized.
   2. Identify the greedy choice: Determine the locally optimal choice at each step based on the current state.
   3. Make the greedy choice: Select the greedy choice and update the current state.
   4. Repeat: Continue making greedy choices until a solution is reached.
2. When should I use a greedy algorithm?
   1. Greedy algorithms are best suited for problems where optimal substructure exists. This means that the optimal solution to the problem can be constructed from the optimal solutions to its subproblems. Examples of problems where greedy algorithms are effective include Dijkstra’s shortest path algorithm, Kruskal’s minimum spanning tree algorithm, and Huffman coding .

## DP

1. Cheatsheet
2. Set 1
   1. Maximum product subarray -
      Maintain product from left and right
   2. Longest increasing subsequence -
      Two pointer from start
   3. Longest common subsequence - check later -
   4. 0-1 Knapsack -
      Check later
      Top down and bottom up approach
3. Set 2
   1. Minimum path sum - done
   2. Coin change - done

## Trie

1. Part  I
   1. feature
      Insert(word)
      search(word)
      startsWith(word)
   2. [https://www.youtube.com/watch?v=dBGUmUQhjaM](https://www.youtube.com/watch?v=dBGUmUQhjaM)
2. Part II
   1. [https://www.youtube.com/watch?v=K5pcpkEMCN0](https://www.youtube.com/watch?v=K5pcpkEMCN0)
   2. feature
      Insert(word)
      countSearch(word)
      countStartsWith(word)
      erase(word)
   3.
3. [https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4](https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4)
   1. Do this playlist

