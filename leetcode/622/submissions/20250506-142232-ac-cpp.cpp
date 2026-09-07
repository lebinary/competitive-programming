/*
 * 622. Design Circular Queue
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 46.1%)
 * Memory: 23.3 MB (beats 95.5%)
 * Submitted: 2025-05-06 14:22:33 UTC
 * URL: https://leetcode.com/submissions/detail/1627047901/
 */

class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
        ListNode(int v, ListNode* next) : val(v), next(next) {}
    };

    int capacity;
    ListNode* first;
    ListNode* last;
public:
    MyCircularQueue(int k) {
        capacity = k;
        first = new ListNode(-1);
        last = first;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ListNode* niw = new ListNode(value);
        if(isEmpty()) first->next = niw;
        else last->next = niw;
        last = niw;

        capacity--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        first->next = first->next->next;
        if(!first->next) last = first;

        capacity++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : first->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : last->val;
    }
    
    bool isEmpty() {
        return first->next == nullptr;
    }
    
    bool isFull() {
        return capacity == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
