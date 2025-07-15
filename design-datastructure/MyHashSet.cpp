#include <bits/stdc++.h>
using namespace std;

// Implementation - 01
// Brute Force Approach
class MyHashSet
{
private:
    vector<int> data;

public:
    MyHashSet() {}

    void add(int key)
    {
        if (find(data.begin(), data.end(), key) == data.end())
        {
            data.push_back(key);
        }
    }

    void remove(int key)
    {
        auto it = find(data.begin(), data.end(), key);
        if (it != data.end())
        {
            data.erase(it);
        }
    }

    bool contains(int key)
    {
        return find(data.begin(), data.end(), key) != data.end();
    }
};

// Implementation - 02
// Using prime and hashing logic
class MyHashSet
{
private:
    // Big Prime Number
    int prime;
    // Vector of List [TABLE]
    vector<list<int>> table;

    // Hash Function
    int hash(int key)
    {
        return key % prime;
    }

    // Search Function
    list<int>::iterator search(int key)
    {
        int h = hash(key);
        return find(table[h].begin(), table[h].end(), key);
    }

public:
    // Constructor
    MyHashSet() : prime(10007), table(prime) {}

    void add(int key)
    {
        int h = hash(key);
        if (!contains(key))
            table[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        auto it = search(key);
        if (it != table[h].end())
            table[h].erase(it);
    }

    bool contains(int key)
    {
        int h = hash(key);
        return search(key) != table[h].end();
    }
};
