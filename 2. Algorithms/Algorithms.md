# ⚙️ Base Algorithms for Data Structures & Problem Solving

> These are the **core algorithms** that form the foundation of most Data Structures & Algorithms and LeetCode questions.  
> Mastering these ensures you can recognize patterns, derive variations, and solve complex problems efficiently.

---

## 🧮 1. Sorting Algorithms

**Intuition:**  
Rearrange elements in ascending or descending order using comparisons or counting techniques.  
Sorting often reveals structure, enables binary search, and simplifies greedy or DP logic.

**Algorithms:**
- **Bubble Sort** — Simple adjacent swaps; educational baseline.
- **Selection Sort** — Repeatedly select the minimum element.
- **Insertion Sort** — Insert each element into its correct position.
- **Merge Sort** — Divide & Conquer, stable sort, O(n log n).
- **Quick Sort** — Partition-based divide & conquer, average O(n log n).
- **Heap Sort** — Uses a max-heap to extract largest repeatedly.
- **Counting Sort / Radix / Bucket Sort** — Non-comparison sorting for integers or digits.

---

## 🔍 2. Searching Algorithms

**Intuition:**  
Efficiently locate an element or property in structured data.

**Algorithms:**
- **Linear Search** — Scan sequentially.
- **Binary Search** — Divide sorted space in half each step.
- **Ternary Search** — For unimodal functions (find max/min point).
- **Jump / Interpolation Search** — Variations on sorted data.
- **Exponential Search** — For unbounded or infinite arrays.

---

## 🔁 3. Recursion & Backtracking

**Intuition:**  
Solve complex problems by breaking them into smaller versions and exploring all configurations.

**Algorithms:**
- **Basic Recursion Template** — Solve + combine subproblems.
- **Permutations / Combinations Generation**
- **N-Queens Problem**
- **Subset / Power Set Generation**
- **Sudoku Solver**
- **Rat in a Maze / Path Finding**

---

## 💡 4. Divide & Conquer

**Intuition:**  
Divide problem → Conquer subproblems → Combine results.

**Algorithms:**
- **Merge Sort**
- **Quick Sort**
- **Binary Search**
- **Fast Exponentiation (Power in Log Time)**
- **Karatsuba Multiplication**
- **Closest Pair of Points**

---

## 📈 5. Dynamic Programming (DP)

**Intuition:**  
Store results of overlapping subproblems to avoid recomputation.

**Core DP Algorithms:**
- **0/1 Knapsack**
- **Longest Common Subsequence (LCS)**
- **Longest Increasing Subsequence (LIS)**
- **Matrix Chain Multiplication**
- **Coin Change (I & II)**
- **Subset Sum / Partition Problem**
- **Edit Distance**
- **Catalan Numbers**
- **Fibonacci (Bottom-Up & Memoization)**

---

## 🌲 6. Graph Algorithms

**Intuition:**  
Model problems as nodes (states) connected by edges (transitions).  
Traverse or analyze for reachability, connectivity, or optimization.

**Core Algorithms:**
- **BFS (Breadth-First Search)**
- **DFS (Depth-First Search)**
- **Topological Sort**
- **Dijkstra’s Algorithm** — Single source shortest path.
- **Bellman-Ford Algorithm** — Detect negative cycles.
- **Floyd-Warshall** — All pairs shortest path.
- **Kruskal’s Algorithm** — MST using Union-Find.
- **Prim’s Algorithm** — MST using Priority Queue.
- **Union-Find / Disjoint Set Union (DSU)**
- **Tarjan’s Algorithm** — Bridges & Articulation Points.
- **Kahn’s Algorithm** — Topological sorting using indegrees.

---

## 🌳 7. Tree Algorithms

**Intuition:**  
Recursive hierarchical data — use DFS or BFS traversal patterns.

**Core Algorithms:**
- **Inorder / Preorder / Postorder Traversal**
- **Level Order (BFS) Traversal**
- **Lowest Common Ancestor (LCA)**
- **Diameter of a Binary Tree**
- **Binary Search Tree (BST) Insert / Delete / Search**
- **Serialize / Deserialize Binary Tree**
- **Segment Tree Build & Query**
- **Fenwick Tree (Binary Indexed Tree)**

---

## 🧮 8. Greedy Algorithms

**Intuition:**  
Make the optimal local choice at each step to reach global optimum (when structure is “greedy-safe”).

**Core Algorithms:**
- **Activity Selection**
- **Huffman Encoding**
- **Job Sequencing with Deadlines**
- **Fractional Knapsack**
- **Interval Scheduling**
- **Minimum Number of Platforms**
- **Greedy Coin Change**

---

## 💾 9. Bit Manipulation Algorithms

**Intuition:**  
Use bitwise operations to represent sets, optimize space, or compute parity efficiently.

**Core Concepts:**
- **Check / Set / Toggle / Clear Bits**
- **Count Set Bits (Brian Kernighan’s Algorithm)**
- **XOR Tricks (Single Number, Subset XOR)**
- **Subset Generation using Bitmask**
- **Power of Two Check**
- **Bitwise DP (Traveling Salesman / Masks)**

---

## ⚙️ 10. Math & Number Theory Algorithms

**Intuition:**  
Use properties of divisibility, primes, modular arithmetic, and combinatorics to optimize.

**Core Algorithms:**
- **GCD / LCM (Euclidean Algorithm)**
- **Sieve of Eratosthenes (Prime Generation)**
- **Modular Exponentiation**
- **Modular Inverse (Fermat’s Little Theorem)**
- **Extended Euclidean Algorithm**
- **Inclusion–Exclusion Principle**
- **Combinations / nCr using Factorials**
- **Chinese Remainder Theorem (CRT)**
- **Fast Power (aⁿ mod m)**

---

## 🧱 11. Heap / Priority Queue Algorithms

**Intuition:**  
Always extract or access the current minimum/maximum efficiently.

**Core Algorithms:**
- **Heapify / Build Heap**
- **Heap Sort**
- **Kth Largest / Smallest Element**
- **Merge K Sorted Lists**
- **Top K Frequent Elements**
- **Median of Data Stream**

---

## 🕸️ 12. String Algorithms

**Intuition:**  
Process sequences of characters efficiently using hashing, pattern matching, or prefix functions.

**Core Algorithms:**
- **KMP (Knuth–Morris–Pratt) Pattern Matching**
- **Rabin-Karp (Rolling Hash)**
- **Z-Algorithm**
- **Manacher’s Algorithm (Longest Palindromic Substring)**
- **Trie Construction / Prefix Search**
- **Suffix Array / Suffix Tree**
- **String Hashing (Polynomial Rolling)**

---

## 🧭 13. Geometry & Spatial Algorithms

**Intuition:**  
Apply mathematical formulas and geometric properties for 2D or 3D problems.

**Core Algorithms:**
- **Orientation Test / Cross Product**
- **Convex Hull (Graham Scan / Jarvis March)**
- **Line Intersection**
- **Closest Pair of Points (Divide & Conquer)**
- **Rotating Calipers (Min Distance Between Shapes)**

---

## 🧮 14. Combinatorics & Probability

**Intuition:**  
Count number of ways to arrange, select, or distribute objects with constraints.

**Core Algorithms:**
- **Permutation & Combination (nPr / nCr)**
- **Derangements Formula**
- **Catalan Numbers**
- **Pascal’s Triangle Generation**
- **Inclusion–Exclusion Counting**
- **Stars and Bars (Distribution of Items)**

---

## 🧩 15. Advanced Data Structure Algorithms

**Intuition:**  
Optimize query/update operations using specialized structures.

**Core Algorithms:**
- **Segment Tree (Range Queries)**
- **Fenwick Tree (Prefix Queries)**
- **Sparse Table (RMQ)**
- **Disjoint Set Union (Union-Find)**
- **Trie (Prefix Matching)**
- **LCA using Binary Lifting**
- **Mo’s Algorithm (Offline Query Processing)**

---

## 🧮 16. Miscellaneous Base Algorithms

**Intuition:**  
Useful in many design or logical problems.

**Algorithms:**
- **Kadane’s Algorithm (Max Subarray Sum)**
- **Floyd’s Cycle Detection (Tortoise & Hare)**
- **Reservoir Sampling**
- **Union by Rank + Path Compression**
- **Binary Exponentiation**
- **Top-K Elements using Min-Heap**
- **Sliding Window Maximum (Deque)**

---

## 🧭 Summary Table

| Category | Core Purpose |
|-----------|---------------|
| Sorting | Arrange data efficiently |
| Searching | Locate elements / boundaries |
| Recursion & Backtracking | Explore all possibilities |
| DP | Reuse overlapping subproblems |
| Graph | Model and traverse relationships |
| Tree | Hierarchical data traversal |
| Greedy | Locally optimal = globally optimal |
| Bit Manipulation | Space and subset optimization |
| Math | Derive formula-based optimizations |
| String | Pattern and prefix-based operations |
| Heap | Prioritize dynamically |
| Geometry | Spatial and coordinate reasoning |

---

> 🧠 **Pro Tip:** Every advanced problem on LeetCode is built on one or more of these base algorithms.  
> Before solving harder variants, make sure you can implement these from scratch confidently.
