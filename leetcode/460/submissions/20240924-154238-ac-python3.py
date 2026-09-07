# 460. LFU Cache
# Difficulty: Hard
# Status: Accepted
# Runtime: 627 ms (beats 5.0%)
# Memory: 82.2 MB (beats 5.4%)
# Submitted: 2024-09-24 15:42:38 UTC
# URL: https://leetcode.com/submissions/detail/1400865191/

class ListNode:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

class LinkedList:
    def __init__(self):
        self.left = ListNode(0)
        self.right = ListNode(0)
        self.left.next, self.right.prev = self.right, self.left
        self.map = {}

    def insert(self, val):
        node = ListNode(val, self.right.prev, self.right)
        node.prev.next = node.next.prev = node
        self.map[val] = node

    def pop(self, val):
        if val in self.map:
            node = self.map[val]
            prev, nxt = node.prev, node.next
            prev.next, nxt.prev = nxt, prev
            del self.map[val]

    def popLeft(self):
        if len(self.map) == 0:
            return None
        val = self.left.next.val
        self.pop(val)
        return val

    def update(self, val):
        self.pop(val)
        self.insert(val)


class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.min_freq = 0
        self.cache = {} # key -> (val, freq)
        self.freq_nodes = {} # freq -> LinkedList

    def update(self, key):
        # 1. remove from (freq -> LinkedList)
        #   edge cases:
            # a. if it is the last element in LinkedList:
                # remove key from freq_nodes
                # increment min_freq

        # 2. insert into (freq + 1 -> LinkedList)
        #   edge cases:
            # (freq+1) does not exist in freq_nodes:
                # init new LinkedList
            # update cache
        
        val, freq = self.cache[key]
        self.freq_nodes[freq].pop(key)

        # Linked list at this freq is empty
        if len(self.freq_nodes[freq].map) == 0:
            del self.freq_nodes[freq]
            if self.min_freq == freq:
                self.min_freq += 1

        freq += 1
        self.cache[key] = (val, freq)

        if freq not in self.freq_nodes:
            self.freq_nodes[freq] = LinkedList()
        self.freq_nodes[freq].insert(key)

    def get(self, key):
        if key not in self.cache:
            return -1

        val, _ = self.cache[key]
        self.update(key)
        return val

    def put(self, key, val):
        if self.capacity == 0:
            return

        # key exists
        if key in self.cache:
            self.cache[key] = (val, self.cache[key][1])
            self.update(key)
        # key not exists
        else:
            # exceed capacity
            if len(self.cache) == self.capacity:
                lfu_key = self.freq_nodes[self.min_freq].popLeft()
                del self.cache[lfu_key]

            self.cache[key] = (val, 1)
            if 1 not in self.freq_nodes:
                self.freq_nodes[1] = LinkedList()
            self.freq_nodes[1].insert(key)
            self.min_freq = 1
