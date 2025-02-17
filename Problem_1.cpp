// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: LRU Cache
// Approach: Linked List
// Time Complexity: O(1)  
// Space Complexity: O(N)

class LRUCache {
    private:
        struct Node {
            int key, value;
            Node* prev;
            Node* next;
            Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        };
    
        unordered_map<int, Node*> map; 
        Node* head;                    
        Node* tail;                    
        int capacity;
    
        // Function to add a node right after the head
        void addToHead(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    
        // Function to remove a node from the linked list
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    
    public:
        // Constructor to initialize LRUCache with a given capacity
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
    
        // Function to get the value of the key if it exists in the cache
        int get(int key) {
            if (map.find(key) == map.end()) {
                return -1;
            }
            Node* node = map[key];
            removeNode(node);
            addToHead(node);
            return node->value;
        }
    
        // Function to insert or update a key-value pair in the cache
        void put(int key, int value) {
            if (map.find(key) != map.end()) {
                Node* node = map[key];
                removeNode(node);
                addToHead(node);
                node->value = value;
                return;
            }
            if (map.size() == capacity) {
                Node* tailPrev = tail->prev;
                removeNode(tailPrev);
                map.erase(tailPrev->key);
                delete tailPrev;
            }
            Node* node = new Node(key, value);
            addToHead(node);
            map[key] = node;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */