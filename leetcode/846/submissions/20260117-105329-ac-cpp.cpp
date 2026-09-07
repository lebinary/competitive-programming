/*
 * 846. Hand of Straights
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 8 ms (beats 96.8%)
 * Memory: 25.3 MB (beats 94.9%)
 * Submitted: 2026-01-17 10:53:30 UTC
 * URL: https://leetcode.com/submissions/detail/1887653337/
 */

class Solution {
  public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int groupCount = 0;

        for (int h : hand) {
            while (!q.empty() && q.top().second == groupSize) {
                groupCount++;
                q.pop();
            };

            if (q.empty()) {
                q.push({h, 1});
                continue;
            }

            auto [prevH, count] = q.top();

            if (prevH + 1 == h) {
                q.pop();
                q.push({h, count + 1});
            } else {
                q.push({h, 1});
            }
        }

        while (!q.empty() && q.top().second == groupSize) {
            groupCount++;
            q.pop();
        }

        return groupCount == n / groupSize;
    }
};
