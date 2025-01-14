/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 class Node {
public:
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    int key, value;
    Node *prev, *next;
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), first(NULL), last(NULL) {}
    
    int get(int key) {
        if (cache.count(key) == 0) return -1;
        if (last != cache[key]) moveNodeToEnd(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->value = value;
            moveNodeToEnd(cache[key]);
            return;
        }
        if (cache.size() == capacity) evictOldest();
        if (!first) {
            first = new Node(key, value);
            last = first;
        }
        else {
            last->next = new Node(key, value);
            last->next->prev = last;
            last = last->next;
        }
        cache[key] = last;
    }

    void moveNodeToEnd(Node* to_move) {
        if (last == to_move) return;
        if (first == to_move) {
            first = first->next;
        }
        else {
            to_move->prev->next = to_move->next;
            to_move->next->prev = to_move->prev;
        }
        last->next = to_move;
        to_move->prev = last;
        to_move->next = NULL;
        last = to_move;
    }

    void evictOldest() {
        Node* tmp = first;
        cache.erase(tmp->key);
        first = first->next;
        if (first) first->prev = NULL;
        delete tmp;
    }
    unordered_map<int, Node*> cache;
    int capacity;
    Node* first;
    Node* last;
};
