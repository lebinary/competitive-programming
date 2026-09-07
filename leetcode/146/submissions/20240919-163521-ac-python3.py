# 146. LRU Cache
# Difficulty: Medium
# Status: Accepted
# Runtime: 586 ms (beats 5.0%)
# Memory: 78.5 MB (beats 20.9%)
# Submitted: 2024-09-19 16:35:21 UTC
# URL: https://leetcode.com/submissions/detail/1395621124/

class Node:
  def __init__(self, key, val):
    self.key = key
    self.val = val
    self.prev, self.next = None, None

class LRUCache:
    def __init__(self, capacity: int):
      self.cap = capacity
      self.cache = {}
      self.left, self.right = Node(-1, -1), Node(-1, -1)
      self.left.next, self.right.prev = self.right, self.left
    
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev
    
    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next, nxt.prev = node, node
        node.prev, node.next = prev, nxt

    def get(self, key: int):
        node = self.cache.get(key, None)

        if node:
            self.remove(node) 
            self.insert(node)
            return node.val
        return -1
    
    def put(self, key: int, val: int):
        node = self.cache.get(key, None)
        if node:
            self.remove(node)
        
        new_node = Node(key, val)
        self.cache[key] = new_node
        self.insert(new_node)

        if len(self.cache) > self.cap:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]
