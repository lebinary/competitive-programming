#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
  public:
    int val;
    Node *prev;
    Node *next;

    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), prev(nullptr), next(nullptr) {}
    Node(int _val, Node *_prev, Node *_next) : val(_val), prev(_prev), next(_next) {}
};

class AllOne {
  public:
    unordered_map<string, Node *> fmap;
    unordered_map<Node *, unordered_set<string>> kmap;
    Node *start, *end;

    AllOne() {
        this->start = initLinkedList();
        this->end = start->next;
    }

    Node *initLinkedList() {
        Node *start = new Node(INT_MIN);
        Node *end = new Node(INT_MAX);
        start->next = end;
        end->prev = start;
        return start;
    }

    Node *insertRight(Node *curr, Node *niw) {
        if (curr == nullptr) curr = initLinkedList();
        niw->next = curr->next;
        niw->prev = curr;
        curr->next->prev = niw;
        curr->next = niw;
        return niw;
    }

    void remove(Node *node) {
        if (node == nullptr) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
    }

    void inc(string key) {
        if (!fmap.count(key)) fmap[key] = start;
        Node *curr = fmap[key], *next = fmap[key]->next;

        // update fmap
        int newFreq = curr->val == INT_MIN ? 1 : curr->val + 1;
        if (next->val == newFreq) {
            fmap[key] = next;
        } else {
            fmap[key] = insertRight(curr, new Node(newFreq));
        }

        // update kmap
        kmap[fmap[key]].insert(key);
        if (kmap.count(curr)) {
            kmap[curr].erase(key);
            if (kmap[curr].size() == 0) {
                remove(curr);
                kmap.erase(curr);
            };
        }
    };

    void dec(string key) {
        Node *curr = fmap[key], *prev = fmap[key]->prev;

        if (curr->val - 1 == 0) {
            kmap[curr].erase(key);
            fmap.erase(key);

            if (kmap[curr].empty()) {
                remove(curr);
                kmap.erase(curr);
            }

            return;
        }

        // update fmap
        if (prev->val == curr->val - 1) {
            fmap[key] = prev;
        } else {
            fmap[key] = insertRight(curr->prev, new Node(curr->val - 1));
        }

        // update kmap
        kmap[fmap[key]].insert(key);
        if (kmap.count(curr)) {
            kmap[curr].erase(key);
            if (kmap[curr].empty()) {
                remove(curr);
                kmap.erase(curr);
            }
        }
    }

    string getMaxKey() {
        if (end->prev == start) return "";
        return *kmap[end->prev].begin();
    }

    string getMinKey() {
        if (start->next == end) return "";
        return *kmap[start->next].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
