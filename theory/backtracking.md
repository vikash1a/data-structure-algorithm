## Backtracking

- Brute force approach for all possible combination
- Used when greedy or dp does not work
- TC - O(k^N) OR O(k!)
- Pseudo Code
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