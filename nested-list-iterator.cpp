/* LC 341
 * Given a nested list of integers, implement an iterator to flatten it.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 * Example 2:
 * Given the list [1,[4,[6]]],
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 */
 
 /**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; i--) {
            s.push(nestedList[i]);
        }
    }

    int next() {
        if(!s.empty()) {
            int res = s.top().getInteger();
            s.pop();
            return res;
        }
    }

    bool hasNext() {
        while(!s.empty()) {
            NestedInteger t = s.top();
            if(t.isInteger()){
                return true;
            } else {
                s.pop();
                vector<NestedInteger> l = t.getList();
                for(int i = l.size()-1; i >= 0; i--) {
                    s.push(l[i]);
                }
            }
        }
        return false;
    }
};

//approach 2 - using iterator. In approach 1, we flatten the list in the constructor. Suppose the list is very long, we want only 2 elements, we do not need to flatten it entirely in the constructor.
class NestedIterator {
    stack<vector<NestedInteger>::iterator> s,e;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(nestedList.begin());
        e.push(nestedList.end());
    }

    int next() {
        if(hasNext()){
        if(!s.empty()) {
            vector<NestedInteger>::iterator it = s.top();
            int res = it->getInteger();
            s.pop();
            s.push(it+1);
            return res;
        }
        }
    }

    bool hasNext() {
        while(!s.empty()) {
            vector<NestedInteger>::iterator it = s.top();
            if(it == e.top()) {
                s.pop();
                e.pop();
            } else if(it->isInteger()){
                return true;
            } else {
                s.pop();
                s.push(it + 1);
                s.push(it->getList().begin());
                e.push(it->getList().end());
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 
 /* Tested.
  * Implementing recursive version or remove will be difficult in c++.
  * Time complexity: O(N) where N is the total number of integer elements.
  * Space complexity: O(N)
  */
