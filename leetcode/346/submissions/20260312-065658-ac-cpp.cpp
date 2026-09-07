/*
 * 346. Moving Average from Data Stream
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 9 ms (beats 7.6%)
 * Memory: 20.9 MB (beats 18.3%)
 * Submitted: 2026-03-12 06:56:58 UTC
 * URL: https://leetcode.com/submissions/detail/1945761770/
 */

class MovingAverage {
public:
    vector<int> prefixSum;
    int windowSize;

    MovingAverage(int size) {
        this->windowSize = size;
    }
    
    double next(int val) {
        if(prefixSum.empty()) prefixSum.push_back(val);
        else {
            int lastSum = prefixSum.back();
            prefixSum.push_back(lastSum + val);
        }

        int n = prefixSum.size();
        if(n <= windowSize) return (double)prefixSum.back() / n;
        return (double)(prefixSum.back() - prefixSum[n - windowSize - 1]) / windowSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */


/** 
Ideas:
- Need to know 2 things: sum and length of a subwindow  

Approach:
- Use prefixSum
- When next():
    - if prefixSum.size < windowSize:
        sum += val;
        prefixSum << sum;
        return prefixSum[-1] / prefixSum.size
    - else:
        sum += val;
        prefixSum << sum;
        return (prefixSum[-1] - prefixSum[-windowSize]) / windowSize
**/
