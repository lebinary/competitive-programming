# 460. LFU Cache
# Difficulty: Hard
# Status: Accepted
# Runtime: 571 ms (beats 5.0%)
# Memory: 80.7 MB (beats 5.4%)
# Submitted: 2024-09-21 12:21:19 UTC
# URL: https://leetcode.com/submissions/detail/1397380420/

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.min_freq = 0
        self.cache = {}
        self.freq_to_nodes = defaultdict(OrderedDict)

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        self._update(node)
        return node[1]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        # if key already exist
        if key in self.cache:
            node = self.cache[key]
            node[1] = value
            self._update(node)
            return
        
        # key not exist
        if len(self.cache) == self.capacity:
            # Remove the LFU item
            lfu_freq = self.min_freq

            # pop left basically
            lfu_key, _ = self.freq_to_nodes[lfu_freq].popitem(last=False)

            
            del self.cache[lfu_key]

            # if lru empty, clear the linkedlist
            if not self.freq_to_nodes[lfu_freq]:
                del self.freq_to_nodes[lfu_freq]
        
        # Add new item
        self.min_freq = 1
        new_node = [key, value, 1]
        self.cache[key] = new_node
        self.freq_to_nodes[1][key] = new_node

    def _update(self, node):
        key, _, freq = node

        # remove node from freq_to_nodes
        del self.freq_to_nodes[freq][key]

        # if freq is empty, clear the linkedlist
        if not self.freq_to_nodes[freq]:
            # remove the freq_key
            del self.freq_to_nodes[freq]

            # this node freq == min_freq, and its the only node with this freq
            if freq == self.min_freq:
                self.min_freq += 1
        
        node[2] = freq = freq + 1
        self.freq_to_nodes[freq][key] = node

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
