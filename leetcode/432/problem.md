# 432. All O`one Data Structure
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

## Example 1:
Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"

## Constraints:
1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

## Thoughts:
- Maybe try 4 dirs linked list, where
  freqmap{[key]: freqNode}
  keyMap{[freqNode]: keyNode}

  START
    |
  freq=7: set
    |
  freq=4: set
    |
  freq=2: set
    |
   END

- When inc: Node1
  Node1.left.right = Node1.right
  Node1.right.left = Node1.left

  if freqNode->next->freq != freqNode->freq + 1:
    niw = new Node(freq + 1)
    freqNode->next->prev = niw
    niw->next = freqNode->next
    freqNode->next = niw
    niw->prev = freqNode

    START = new Node(), END = new Node()
    START.next = END
    END.prev = START
    keyMap[niw] = START

## Questions:
How much time have I spent, end-to-end? ~2 hours
What were the trickiest aspects? Where did you lose the most time? - I was going down the path of using 2 heaps (too simple), then tried 4 directions Linked List (which is too complicated)
What are some lessons/insights I gained from this problem? - doubly-linked list can be used to find max/min quickly O(1)
What would I do differently if I had extra time? What’s remaining to improve? - Try singly linked-list
What did I do well? - Able to come up with solution after some hints
Did you use any hints, if yes, what? (please do not give up and look up the hints quickly. if you do need to look up the hints, only use the ones given on the problem page one by one, and DON'T look at youtube videos or full solutions, until you try really hard) Yes, i did, I read the first few discussions and see "LRU cache"
How difficult was the problem (1 super trivial, 10 extremely difficult) (answer this question three times separately for a) implementing quickly b) finding the right approach c) overall) probably 8, would not have been able to solve it with without hints
What's the time & space complexity? TC: O(1), SC: O(n)
