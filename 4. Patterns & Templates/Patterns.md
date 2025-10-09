# 🧩 DSA + LeetCode Problem-Solving Patterns

> This document summarizes **core problem-solving patterns** used across Data Structures, Algorithms, and LeetCode questions.  
> Each pattern highlights the **intuition** — the mental model to identify and apply it effectively.

---

## 🧠 Array & Sliding Window
**Intuition:**  
Maintain a “window” (contiguous subarray) that slides over the array to track sums, counts, or frequencies dynamically.  
Expand or shrink the window to satisfy given conditions efficiently.

---

## ⚔️ Two Pointers
**Intuition:**  
Use two indices moving at different speeds or directions to process data (often sorted).  
Useful for finding pairs, removing duplicates, or merging sorted sequences.

---

## 🧮 Hashing & Counting
**Intuition:**  
Replace nested searches with constant-time lookups using hash maps or sets.  
Count frequencies, check existence, or track prefix states to reduce complexity from O(n²) to O(n).

---

## ⚙️ Sorting & Greedy
**Intuition:**  
Sort data to reveal structure or order, then make the best local choice (greedy) at each step to achieve a global optimum.

---

## 🎯 Binary Search
**Intuition:**  
Search over **monotonic functions or sorted spaces**, not just arrays.  
Used to find boundaries, thresholds, or the smallest/largest valid answer.

---

## ➕ Prefix Sum & Difference Array
**Intuition:**  
Precompute cumulative information to answer range queries in O(1).  
Transforms repeated computation into subtraction of prefix values.

---

## 📊 Stack / Monotonic Stack
**Intuition:**  
Use a stack to maintain elements in increasing or decreasing order.  
Helps efficiently find the “next greater/smaller” element or maintain history of state transitions.

---

## 🚦 Queue / Deque
**Intuition:**  
Use FIFO structure to manage elements by arrival order or maintain min/max within a window using a deque (monotonic queue).

---

## 🔗 Linked List
**Intuition:**  
Manipulate node connections directly for operations like reversal, cycle detection, merging, or partitioning without extra space.

---

## 🌳 Binary Tree / BST
**Intuition:**  
Use recursion to process subtrees independently.  
BSTs rely on order properties — leverage them to prune searches or count paths.

---

## 🕸️ Graphs
**Intuition:**  
Model relationships as nodes and edges.  
Use traversal (BFS/DFS) for reachability, shortest path algorithms (Dijkstra, BFS for unweighted), or cycle detection.

---

## 🔁 Recursion & Backtracking
**Intuition:**  
Explore all configurations by making decisions step-by-step, then undoing them (backtrack).  
Used for generating subsets, permutations, and constraint satisfaction problems.

---

## 💡 Dynamic Programming
**Intuition:**  
Break a problem into overlapping subproblems and store results.  
Think: **“Can I build the answer using solutions to smaller inputs?”**  
Two key dimensions: optimal substructure and overlapping subproblems.

---

## 🏗️ Heap / Priority Queue
**Intuition:**  
Retrieve smallest/largest elements efficiently.  
Use it for scheduling, top-k problems, or Dijkstra’s algorithm where you always pick the current best option.

---

## 🔢 Combinatorics & Math
**Intuition:**  
Count arrangements, selections, or distributions using factorials, binomial coefficients, or inclusion–exclusion.  
Often transforms recursion into a formula.

---

## 🧩 Bit Manipulation
**Intuition:**  
Use bits as compact representations of states or subsets.  
Allows fast parity checks, masks, and dynamic programming on subsets.

---

## ✂️ Intervals & Sweep Line
**Intuition:**  
Sort by start/end points and process events in order while maintaining an active set.  
Used in scheduling, merging, or overlap detection.

---

## 🔄 Topological Sort
**Intuition:**  
Linearize a directed acyclic graph (DAG) according to dependencies.  
Core for scheduling tasks and evaluating order-based problems.

---

## 🔗 Union-Find / Disjoint Set
**Intuition:**  
Group connected elements and efficiently check whether two elements belong to the same set.  
Used for Kruskal’s MST and connectivity queries.

---

## 🧮 Number Theory & Modular Arithmetic
**Intuition:**  
Use properties of divisibility, primes, or modular inverses to simplify problems involving large numbers or cyclic patterns.

---

## 📈 Binary Search on Answer
**Intuition:**  
Instead of searching for an element, search over the range of possible answers.  
Used when the answer space is numeric and the condition is monotonic (true → false).

---

## 🗺️ Matrix & Grid Traversal
**Intuition:**  
Treat 2D grids as graphs — use BFS/DFS to explore cells.  
Track visited states and handle boundaries to prevent infinite loops.

---

## 🌲 Segment Tree / Fenwick Tree
**Intuition:**  
Store partial information about array segments to query and update ranges efficiently.  
Ideal for sum, min/max, or frequency queries in logarithmic time.

---

## 🧵 Trie / String Hashing
**Intuition:**  
Store strings by prefix to enable fast lookup, prefix checks, or counting unique substrings.

---

## 💎 Greedy + Sorting Hybrids
**Intuition:**  
Sort first to expose greedy choices, then iterate linearly making optimal local selections based on constraints.

---

## 🧭 Meet in the Middle / Subset Tricks
**Intuition:**  
Split problem into two halves, precompute all subset combinations for each, and combine results efficiently.

---

## 🎮 Game Theory
**Intuition:**  
Analyze optimal play in turn-based problems using parity, recursion, or DP to decide win/loss states.

---

## 🧰 Miscellaneous Patterns
**Intuition:**  
Includes simulation, probability, randomization, or data structure design patterns.  
Recognize by problem behavior rather than category.

---

## 🏁 Summary

| Category | Core Idea |
|-----------|------------|
| **Sliding Window** | Adjust range dynamically |
| **Two Pointers** | Move two indices intelligently |
| **DP** | Reuse solutions to subproblems |
| **Graph** | Model relationships & traverse |
| **Binary Search on Answer** | Search over solution space |
| **Combinatorics** | Count arrangements mathematically |

---

> 📘 *Remember:* Patterns are not formulas — they’re **mental templates** to recognize and apply creatively across problems.
