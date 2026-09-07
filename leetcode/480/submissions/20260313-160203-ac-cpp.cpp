/*
 * 480. Sliding Window Median
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 62 ms (beats 56.2%)
 * Memory: 40.1 MB (beats 79.8%)
 * Submitted: 2026-03-13 16:02:03 UTC
 * URL: https://leetcode.com/submissions/detail/1947161646/
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        priority_queue<int> leftPar;
        priority_queue<int, vector<int>, greater<int>> rightPar;
        unordered_map<int, int> removed;
        int leftSize = 0, rightSize = 0;
        
        for(int i = 0; i < k; ++i) {
            insertAndBalance(leftPar, rightPar, leftSize, rightSize, nums[i]);
        }
        res.push_back(getMedian(leftPar, rightPar, leftSize, rightSize));

        for(int i = k; i < n; ++i) {
            int preMedian = res.back(), numToRemove = nums[i-k];
            removeAndBalance(leftPar, rightPar, leftSize, rightSize, numToRemove, preMedian, removed);

            insertAndBalance(leftPar, rightPar, leftSize, rightSize, nums[i]);

            cleanHeaps(leftPar, rightPar, removed);

            res.push_back(getMedian(leftPar, rightPar, leftSize, rightSize));
        }

        return res;
    }

    void cleanHeaps(auto& leftPar, auto& rightPar, auto& removed) {
        while(!leftPar.empty() && removed[leftPar.top()] > 0) {
            removed[leftPar.top()]--;
            leftPar.pop();
        }
        while(!rightPar.empty() && removed[rightPar.top()] > 0) {
            removed[rightPar.top()]--;
            rightPar.pop();
        }
    }

    void removeAndBalance(auto& leftPar, auto& rightPar, int& leftSize, int& rightSize, int num, int median, auto& removed) {
        removed[num]++;
        if(num <= median) leftSize--;
        else rightSize--;

        if(leftSize < rightSize) {
            leftPar.push(rightPar.top()); leftSize++;
            rightPar.pop(); rightSize--;
        } else if(leftSize > rightSize + 1) {
            rightPar.push(leftPar.top()); rightSize++;
            leftPar.pop(); leftSize--;
        }
    }

    // LC295
    void insertAndBalance(auto& leftPar, auto& rightPar, int& leftSize, int& rightSize, int num) {
        leftPar.push(num); leftSize++;
        rightPar.push(leftPar.top()); rightSize++;
        leftPar.pop(); leftSize--;
        if(leftSize < rightSize) {
            leftPar.push(rightPar.top()); leftSize++;
            rightPar.pop(); rightSize--;
        }
    }

    double getMedian(auto& leftPar, auto& rightPar, int& leftSize, int& rightSize) {
        if((leftSize + rightSize) % 2 == 1)
            return (double)leftPar.top();
        return ((double)leftPar.top() + rightPar.top()) * 0.5;
    }
};

/**
Approach 1: sort each k window, pick the median out
TC: O(n * klogk)

Approach 2: binary search + validator
- For each window k, keep track of min/max
- Binary search on the min and max
- Validator: if value >= (k + 1) / 2
TC: O(n * logV * k/2)

Approach 3: monotonic deque
- Invariant: instead of keep the min, we keep the (k+1)/2-th minimum value
- for each i:
    while nums[dq[-1]] > nums[i]: pop
    dq << i
    
    while dq[0] <= i - (k+1)/2: dq.pop_front
    res << dp[0]
return res
=> WONT WORK, deque not guaratee to have at least (k+1)/2 elements inside it at all time

Approach 4: use 2 heaps, same trick as LC295
- leftHeap: maxHeap
- rightHeap: minHeap
- for each i:
    leftHeap << {val, i}
    while leftHeap.top[1] < i - k: leftHeap.pop
    rightHeap << leftHeap.pop

    if rightHeap.size > leftHeap.size:
        leftHeap << rightHeap.pop

    res << leftHeap.top
return res
TC: O(n * logk)
SC: O(n)
=> WONT WORK, both heaps can consist of index that are out of the window
=> Solution: need to clean both heaps before rebalance

Approach 4.a: use 2 heaps, but with virtual sizes
- for each i:
    removedSet << i - k
    clean Left Heap
    cleean Right Heap
    if nums[i-k] <= leftHeap.top: leftSize--
    else rightSize--

    leftHeap << { nums[i], i }
    rightHeap << leftHeap.pop()
    rightSize++


    if leftHeap.size < rightHeap.size:
        leftHeap << rightHeap.pop
        rightSize--
        leftSize++
    
    if (leftSize + rightSize) is odd:
        res << leftSize.top
    else:
        res << (leftSize.top + rightSize.top) * 0.5

return res

**/
