# 🧵 STRING & CHARACTER MANIPULATION — CHEAT SHEET

Interview-ready • Competitive Programming • Quick Revision

---

## 📌 1. String Basics

```cpp
string s = "Ayush";
int n = s.size();        // or s.length()
bool e = s.empty();      // string empty
```

🔠 2. Character Case Conversion
✅ Best Practice (Standard Library)
cpp
Copy code
#include <algorithm>
#include <cctype>

transform(s.begin(), s.end(), s.begin(), ::tolower);
transform(s.begin(), s.end(), s.begin(), ::toupper);
⚠️ ASCII-Based (Educational)
cpp
Copy code
if (ch >= 'A' && ch <= 'Z') ch += 32;  // Upper → Lower
if (ch >= 'a' && ch <= 'z') ch -= 32;  // Lower → Upper
🔤 3. Alphabet Indexing (VERY IMPORTANT)
Lowercase Index
cpp
Copy code
int idx = ch - 'a';   // 'a'→0, 'b'→1, ..., 'z'→25
Uppercase Index
cpp
Copy code
int idx = ch - 'A';   // 'A'→0, 'B'→1, ..., 'Z'→25
Frequency Array
cpp
Copy code
int freq[26] = {0};
for (char ch : s)
    if (ch >= 'a' && ch <= 'z')
        freq[ch - 'a']++;
🔄 4. Index → Character Conversion
Lowercase Character
cpp
Copy code
char ch = index + 'a';   // 0→'a', 1→'b'
Uppercase Character
cpp
Copy code
char ch = index + 'A';   // 0→'A', 1→'B'
🧠 5. Summary: ch ± 'A' / 'a'
Expression	Meaning
ch - 'a'	lowercase → index (0–25)
ch - 'A'	uppercase → index (0–25)
index + 'a'	index → lowercase char
index + 'A'	index → uppercase char

✔ Works only when character is in valid range
❌ Undefined for symbols / digits

🔄 6. Reverse String
cpp
Copy code
reverse(s.begin(), s.end());
Manual:

cpp
Copy code
int l=0, r=s.size()-1;
while(l<r) swap(s[l++], s[r--]);
✂️ 7. Substring
cpp
Copy code
string sub = s.substr(start, length);
string sub = s.substr(start);  // till end
🔍 8. Find / Search
cpp
Copy code
if (s.find("ush") != string::npos)
    cout << "Found";
🔁 9. Replace
cpp
Copy code
s.replace(0, 2, "Hi");
Replace all:

cpp
Copy code
while (s.find("aa") != string::npos)
    s.replace(s.find("aa"), 2, "b");
➕ 10. Concatenation
cpp
Copy code
s += " Poojari";
s.append(" Developer");
🧹 11. Remove Characters
Remove spaces
cpp
Copy code
s.erase(remove(s.begin(), s.end(), ' '), s.end());
Remove non-alphabets
cpp
Copy code
s.erase(remove_if(s.begin(), s.end(),
    [](char c){ return !isalpha(c); }), s.end());
🔢 12. String ↔ Number
String → Number
cpp
Copy code
int x = stoi("123");
long y = stol("456");
Number → String
cpp
Copy code
string s = to_string(100);
🔁 13. Palindrome Check
cpp
Copy code
string t = s;
reverse(t.begin(), t.end());
if (s == t) cout << "Palindrome";
Optimized:

cpp
Copy code
int l=0, r=s.size()-1;
while(l<r)
    if(s[l++] != s[r--]) return false;
🔠 14. Count Vowels
cpp
Copy code
int v=0;
for(char c:s)
    if(string("aeiouAEIOU").find(c)!=string::npos)
        v++;
🔤 15. Sort String
cpp
Copy code
sort(s.begin(), s.end());                 // Ascending
sort(s.begin(), s.end(), greater<char>());// Descending
🔁 16. Remove Duplicates
cpp
Copy code
sort(s.begin(), s.end());
s.erase(unique(s.begin(), s.end()), s.end());
📊 17. Most Frequent Character
cpp
Copy code
int freq[256]={0};
for(char c:s) freq[c]++;

char ans; int mx=0;
for(int i=0;i<256;i++)
    if(freq[i]>mx) mx=freq[i], ans=i;
🔤 18. Anagram Check
cpp
Copy code
sort(a.begin(), a.end());
sort(b.begin(), b.end());
if (a == b) cout << "Anagram";
🔄 19. Split String
cpp
Copy code
#include <sstream>

stringstream ss(s);
string word;
while(ss >> word)
    cout << word << endl;
⚡ 20. Fast I/O
cpp
Copy code
ios::sync_with_stdio(false);
cin.tie(NULL);

```
| Trick        | Usage |
|-------------|-------|
| `ch - 'a'`   | Alphabet indexing |
| `tolower()` | Safe lowercase conversion |
| `substr()`  | Extract substring |
| `find()`    | Pattern search in string |
| `reverse()` | Reverse a string |
| `stoi()`    | Convert string → integer |
| `unique()`  | Remove duplicate characters |

```
## INTERVIEW GOLDEN RULES
✅ Use tolower() / toupper()

❌ Avoid +32 / -32 in real code

⭐ ch - 'a' & index + 'a' are MUST-KNOW

⭐ Strings are mutable in C++

📌 One-Line Memory Trick
Characters are integers → subtract to get index, add to get character

---