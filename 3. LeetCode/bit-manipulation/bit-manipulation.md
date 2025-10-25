# ⚡️ BIT MANIPULATION ROADMAP (Step-by-Step)

## 🧩 1. Basics of Binary Representation

Every integer in memory is represented as binary bits (0s and 1s).

Example:
```
5 → 0101 (in 4 bits)
7 → 0111
```

Operations work directly on these bits.


## ⚙️ 2. Common Bitwise Operators

| Operator | Symbol | Meaning | Example |
|-----------|---------|----------|----------|
| AND | `&` | 1 if both bits are 1 | `5 & 3 = 0101 & 0011 = 0001 (1)` |
| OR | `\|` | 1 if at least one bit is 1 | `5 \| 3 = 0111 (7)` |
| XOR | `^` | 1 if bits differ | `5 ^ 3 = 0110 (6)` |
| NOT | `~` | Inverts bits | `~5 = -(5+1) = -6` |
| Left Shift | `<<` | Shift bits left | `5 << 1 = 10` |
| Right Shift | `>>` | Shift bits right | `10 >> 1 = 5` |

---

## 💡 3. Common Bit Tricks (Must Memorize)
- ✅ 1. Check if a bit is set
if (num & (1 << i))   // checks if ith bit is 1

- ✅ 2. Set a bit
num |= (1 << i);

- ✅ 3. Clear a bit
num &= ~(1 << i);

- ✅ 4. Toggle (flip) a bit
num ^= (1 << i);

- ✅ 5. Count set bits (Hamming weight)

- Built-in: __builtin_popcount(n)

Manual:
```
int count = 0;
while (n) {
    n &= (n - 1); // clears the lowest set bit
    count++;
}
```

- ✅ 6. Check if number is power of 2
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);

- ✅ 7. Get rightmost set bit
int rightmost = n & (-n);

- ✅ 8. Turn off rightmost set bit
n = n & (n - 1);

## 🧠 4. Bitwise Thinking Patterns
Goal	Bit Idea
- Find unique element (others twice)	XOR cancels duplicates
- Swap two numbers without temp	a ^= b; b ^= a; a ^= b;
- Detect odd/even	n & 1 (1 if odd)
- Subset generation	Use bits to represent inclusion/exclusion
- Count bits	__builtin_popcount()
- Masking	Extract or ignore parts of numbers

## 🧮 5. Example Questions (Progression)
- Level 1 — Fundamentals
### Problem	Concept
```        
136. Single Number
	XOR cancels duplicates
191. Number of 1 Bits
	Counting bits
231. Power of Two
	n & (n-1) check
190. Reverse Bits
	Bit shifting
```

- 🔹 Level 2 — Advanced XOR Applications
```
Problem	Concept
137. Single Number II
	Bits mod 3 logic
260. Single Number III
	Partition using diff bit
268. Missing Number
	XOR with indices
389. Find the Difference
	XOR between two strings
🔹 Level 3 — Masks & Dynamic Programming
Problem	Concept
78. Subsets
	Bitmask subset generation
90. Subsets II
	Dedup subsets
691. Stickers to Spell Word
	Bitmask DP
980. Unique Paths III
	Bitmask backtracking
🔹 Level 4 — Bit DP / State Compression
Problem	Concept
1434. Number of Ways to Wear Different Hats
	DP with bitmasking
847. Shortest Path Visiting All Nodes
	BFS + Bitmask DP
1125. Smallest Sufficient Team
	Bitmask DP
```

- 🧩 6. Real-World Analogy

Bits act like switches 🔘:

Each bit = ON/OFF (1/0)

A 32-bit integer = 32 switches to represent states
E.g., for subset problems, each bit = whether an element is in or out.

- 🧠 7. Practice Path Summary
Stage	Focus	Examples
🥉 Basic	AND, OR, XOR, shift	136, 191, 231
🥈 Intermediate	XOR patterns, masking	137, 260, 268
🥇 Advanced	Bitmask DP	847, 1125, 1434
⚡️ 8. Quick Reference Summary

## Operation	Code	Use
Check ith bit	(n >> i) & 1	Get bit value
Set ith bit	`n	= (1 << i)`
Clear ith bit	n &= ~(1 << i)	Make it 0
Toggle ith bit	n ^= (1 << i)	Flip
Count bits	__builtin_popcount(n)	Count 1s
Power of 2	(n & (n - 1)) == 0	Check
🚀 Recommended Practice Plan
Day	Focus	Problems
Day 1	Basics + operations	136, 191, 231
Day 2	XOR logic	137, 260, 268
Day 3	Masking + Subsets	78, 90
Day 4	Advanced DP	847, 1125
Day 5	Revision + Mock	

Would you like me to create a visual “Bit Manipulation Cheat Sheet” (with diagrams showing AND, OR, XOR, and bit toggling effects)? It’s great for quick reference while practicing.

You said:
Give this .md format
ChatGPT said:

## 💡 3. Common Bit Tricks

### ✅ Check if a bit is set
```cpp
if (num & (1 << i))   // checks if ith bit is 1

✅ Set a bit
num |= (1 << i);

✅ Clear a bit
num &= ~(1 << i);

✅ Toggle (flip) a bit
num ^= (1 << i);

✅ Count set bits (Hamming weight)
int count = 0;
while (n) {
    n &= (n - 1); // clears lowest set bit
    count++;
}


Or use built-in:

__builtin_popcount(n);

✅ Check if number is power of 2
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);

✅ Get rightmost set bit
int rightmost = n & (-n);

✅ Turn off rightmost set bit
n = n & (n - 1);
```

## 🧠 4. Bitwise Thinking Patterns
Goal	Bit Idea
- Find unique element (others twice)	XOR cancels duplicates
- Swap two numbers without temp	a ^= b; b ^= a; a ^= b;
- Detect odd/even	n & 1
- Subset generation	Use bits to represent inclusion/exclusion
- Count bits	__builtin_popcount()
- Masking	Extract or ignore parts of numbers

## 🧮 5. Example Questions (Progression)
- Level 1 — Fundamentals
```
Problem	Concept
136. Single Number
	XOR cancels duplicates
191. Number of 1 Bits
	Counting bits
231. Power of Two
	n & (n-1) check
190. Reverse Bits
	Bit shifting
```
- Level 2 — Advanced XOR Applications
```
Problem	Concept
137. Single Number II
	Bits mod 3 logic
260. Single Number III
	Partition using diff bit
268. Missing Number
	XOR with indices
389. Find the Difference
	XOR between two strings
```
- Level 3 — Masks & Dynamic Programming
```
Problem	Concept
78. Subsets
	Bitmask subset generation
90. Subsets II
	Dedup subsets
691. Stickers to Spell Word
	Bitmask DP
980. Unique Paths III
	Bitmask backtracking
``` 
- Level 4 — Bit DP / State Compression
Problem	Concept
```
1434. Number of Ways to Wear Different Hats
	DP with bitmasking
847. Shortest Path Visiting All Nodes
	BFS + Bitmask DP
1125. Smallest Sufficient Team
	Bitmask DP
```

## 🧩 6. Real-World Analogy

Bits act like switches 🔘:

Each bit = ON/OFF (1/0)

A 32-bit integer = 32 switches to represent states
Example: For subset problems, each bit = whether an element is in or out.

## 🧠 7. Practice Path Summary
Stage	Focus	Examples
```
🥉 Basic:    AND, OR, XOR, shift	| 136, 191, 231
🥈 Intermediate	XOR patterns, masking	| 137, 260, 268
🥇 Advanced	Bitmask DP	        | 847, 1125, 1434
```
##⚡️ 8. Quick Reference Summary
Operation	Code	Use
```
- Check ith bit	(n >> i) & 1	Get bit value
- Set ith bit	`n	= (1 << i)`
- Clear ith bit	n &= ~(1 << i)	Make it 0
- Toggle ith bit	n ^= (1 << i)	Flip bit
- Count bits	__builtin_popcount(n)	Count 1s
- Power of 2	(n & (n - 1)) == 0	Check
```
## 🚀 9. Recommended 5-Day Practice Plan
Day	Focus	Problems
Day 1	Basics + operations	136, 191, 231
Day 2	XOR logic	137, 260, 268
Day 3	Masking + Subsets	78, 90
Day 4	Advanced DP	847, 1125
Day 5	Revision + Mock	
## ✨ Summary

Bit manipulation gives you constant-time hacks for mathematical and logical operations.
It’s the foundation for XOR problems, subset generation, and state compression DP.

“Once you master bits, everything else looks slower.” ⚙️

---