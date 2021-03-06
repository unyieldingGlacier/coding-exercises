/* LC 380
 * Design a data structure that supports all following operations in average O(1) time.
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 * Example:
 // Init an empty set.
RandomizedSet randomSet = new RandomizedSet();
// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);
// Returns false as 2 does not exist in the set.
randomSet.remove(2);
// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);
// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();
// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);
// 2 was already in the set, so return false.
randomSet.insert(2);
// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
 */

class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> A;
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        A.push_back(val);
        m[val] = A.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int idx = m[val];
        A[idx] = A[A.size()-1];
        m[A[A.size()-1]] = idx;
        A.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%A.size();
        int val = A[r];
        return val;
    }
};

/* Tested.
 * Note1: removeRandom() just needs a call to remove(val) at line 56.
 * Note2: To use with templates, refer to the hashtable problem.
 * Time complexity: O(1)
 * Space complexity: O(n) where n is the number of elements.
 */
