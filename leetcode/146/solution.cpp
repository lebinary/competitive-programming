#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
  public:
    int val, key;
    Node *prev;
    Node *next;

    Node(int _val, int _key) {
        val = _val;
        key = _key;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
  public:
    int cap;
    unordered_map<int, Node *> map;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node *n = map[key];
        remove(n);
        insert(n);
        return n->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *n = map[key];
            remove(n);
            insert(n);
            n->val = value;
            return;
        }
        if (map.size() >= cap) {
            Node *n = head->next;
            remove(n);
            map.erase(n->key);
        }

        Node *n = new Node(value, key);
        insert(n);
        map[key] = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
