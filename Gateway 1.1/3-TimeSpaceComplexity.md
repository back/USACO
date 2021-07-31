# Time/Space Complexity

In order to pass USACO, your program needs to finish running within a certain timeframe. This limit is 1 ~ 4 seconds for Java submissions. A conservative estimate for the number of operations the grading server can handle per second is $10^8$.

# Big O Notation

The worst-case complexity of processing data population of **n** as a function of (n)

### $O(1)$
The algorithm executes a constant number of operations

### $O(n)$
The execution time is linear to the processing population
```Java
for(int i = 1; i <= n; i++){
    // constant time code her
}
```

### $O(n^2)$
The worst case of double loop
```Java
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
        // constant time code here
    }
}

```

### Other Common Complexities and Constraints

- Constant
  - Mathematical formulas that just calculate an answer: O(1)
  - Unordered set/map: O(1) per operation
- Fast
  - **Binary search**: O(log n)
  - Ordered set/map or priority queue: O(log n) per operation
- Common
  - Reading in n items of input: O(n)
  - Iterating through an array or a list of n elements: O(n)
  - Sorting: usually O(n log n) for default sorting algorithms (mergesort, quicksort)
- Slow
  - Iterating through all subsets of size k of the input elements: $O(n^k)$
    - For example, iterating through all triplets is $O(n^3)$.
  - Iterating through all permutations: $O(n!)$
