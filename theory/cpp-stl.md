## Search

### binary search
 - Use case: Checks if a value exists in a sorted container (like a vector or array). 
 - Returns: true if the element is found, false otherwise. 
 - bool binary_search(InputIterator first, InputIterator last, const T& value);

### lower_bound
 - Purpose: Finds the first position where a given value could be inserted without violating order (i.e., the first element ≥ value).
 - Returns: Iterator to the first element that is not less than (>=) the value.
 - std::lower_bound(start, end, value);

### upper_bound
 - Purpose: Finds the first position after all occurrences of a value (i.e., the first element > value).
 - Returns: Iterator to the first element that is greater than (>) the value.
 - std::lower_bound(start, end, value);
