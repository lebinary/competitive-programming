# 146. LRU Cache
# Difficulty: Medium
# Status: Accepted
# Runtime: 558 ms (beats 5.0%)
# Memory: 78.3 MB (beats 21.1%)
# Submitted: 2024-09-10 14:39:12 UTC
# URL: https://leetcode.com/submissions/detail/1385474291/

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
    
    def remove(self, node: Node):
      prev, nxt = node.prev, node.next
      prev.next , nxt.prev = nxt, prev
    
    def insertRight(self, node: Node):
      prev, nxt = self.right.prev, self.right
      prev.next = nxt.prev = node # adjst pointer of right.prev and right
      node.prev, node.next = prev, nxt # fit node in between right.prev and right

    def get(self, key: int) -> int:
      node = self.cache.get(key, None)
      if node:
        # remove and insert back to update least recent timeline
        self.remove(node)
        self.insertRight(node)
        return node.val
      return -1

    def put(self, key: int, value: int) -> None:
      node = self.cache.get(key, None)
      if node:
        self.remove(node)
      
      new_node = Node(key, value)
      self.cache[key] = new_node
      self.insertRight(new_node)

      # remove lru if exceed capacity
      if len(self.cache) > self.cap:
        lru = self.left.next
        self.remove(lru)
        del self.cache[lru.key]
