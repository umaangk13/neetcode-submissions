class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node* lru; // Dummy head
    Node* mru; // Dummy tail
    int limit;

    // Helper: Removes a specific node from the linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Adds a node right before the MRU dummy tail
    void addNode(Node* node) {
        Node* prevNode = mru->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = mru;
        mru->prev = node;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        lru = new Node(-1, -1);
        mru = new Node(-1, -1);
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // Key doesn't exist
        }
        
        Node* resNode = mp[key];
        int result = resNode->val;
        
        // Mark as recently used by moving it to the back
        removeNode(resNode);
        addNode(resNode);
        
        return result;
    }
    
    void put(int key, int value) {
        // 1. If the key already exists, remove the old node first
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            removeNode(existingNode);
            mp.erase(key);
            delete existingNode; // Prevent memory leak
        }
        
        // 2. If we are at capacity, evict the LRU node (right after dummy head)
        if (mp.size() == limit) {
            Node* lruNode = lru->next;
            removeNode(lruNode);
            mp.erase(lruNode->key);
            delete lruNode;
        }
        
        // 3. Insert the new node
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};