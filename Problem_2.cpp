// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Flattern Nested List Integer
// Approach: Stack
// Time Complexity: O(N) 
// Space Complexity: O(N)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 class NestedIterator {
    private:
        stack<vector<NestedInteger>::iterator> begins, ends;
        int nextVal;
    
    public:
        NestedIterator(vector<NestedInteger>& nestedList) {
            begins.push(nestedList.begin());
            ends.push(nestedList.end());
        }
    
        int next() { return nextVal; }
    
        // Checks if there is a next integer available
        bool hasNext() {
            while (!begins.empty()) {
                if (begins.top() == ends.top()) {
                    begins.pop();
                    ends.pop();
                } else {
                    auto it = begins.top();
                    begins.top()++;
                    if (it->isInteger()) {
                        nextVal = it->getInteger();
                        return true;
                    }
                    begins.push(it->getList().begin());
                    ends.push(it->getList().end());
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