# Expected Knowledge
---
- Learned at least one programming language
 - C/C++
 - Java
 - Python
 - PASCAL
- Variables
- Data types
- Reading Input
- Writing Output
- Loops
- If / Else
- Logical operators
- Arrays
 - Multidimensional Arrays
- Functions
 - Recursion (a function calling itself)

In particular, contestants using Java should be familiar with roughly the <u>first half and ending part</u> of AP Computer Science A (excluding the Class Oriented sections).

# Data Types
---

### int
The 32-bit integer supports values between **−2 147 483 648** and **2 147 483 647**, which is roughly equal to ± $2×10^9$


### float (double)
It is important to know that floating point numbers are **not** exact, because the binary architecture of computers can only store decimals to a certain precision. Hence, we should always expect that floating point numbers are slightly off.

Contest problems will mark as correct any output that is within a certain range of the judge’s answer.

### char
Remember they can be calculated by +, -, *, /; Please refer to the ASCII table below for specific values

![](https://upload.wikimedia.org/wikipedia/commons/d/dd/ASCII-Table.svg)

### String
Strings are effectively arrays of characters. Most time you need this to access the character at a certain index and take substrings of the string.

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

- Mathematical formulas that just calculate an answer: O(1)
- Unordered set/map: O(1) per operation
- **Binary search**: O(log n)
- Ordered set/map or priority queue: O(log n) per operation
- Prime factorization of an integer, or checking primality or compositeness of an integer: O(√n)
- Reading in n items of input: O(n)
- Iterating through an array or a list of n elements: O(n)
- Sorting: usually O(n log n) for default sorting algorithms (mergesort, quicksort)
- Iterating through all subsets of size k of the input elements: $O(n^k)$
 - For example, iterating through all triplets is $O(n^3)$.
- Iterating through all permutations: $O(n!)$
