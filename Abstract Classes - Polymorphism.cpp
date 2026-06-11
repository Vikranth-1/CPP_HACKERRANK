#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    
    void set(int key, int value) {
        // If key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            
            // Move to front (most recently used)
            if (node != head) {
                // Remove from current position
                if (node->prev) node->prev->next = node->next;
                if (node->next) node->next->prev = node->prev;
                if (node == tail) tail = node->prev;
                
                // Insert at front
                node->prev = NULL;
                node->next = head;
                if (head) head->prev = node;
                head = node;
                if (!tail) tail = head;
            }
        }
        // If key doesn't exist
        else {
            // Create new node
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            
            // Insert at front
            if (!head) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            
            // If capacity exceeded, remove least recently used (tail)
            if (mp.size() > cp) {
                Node* toRemove = tail;
                tail = tail->prev;
                if (tail) tail->next = NULL;
                else head = NULL;
                
                mp.erase(toRemove->key);
                delete toRemove;
            }
        }
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            
            // Move to front (most recently used)
            if (node != head) {
                // Remove from current position
                if (node->prev) node->prev->next = node->next;
                if (node->next) node->next->prev = node->prev;
                if (node == tail) tail = node->prev;
                
                // Insert at front
                node->prev = NULL;
                node->next = head;
                if (head) head->prev = node;
                head = node;
                if (!tail) tail = head;
            }
            
            return node->value;
        }
        
        return -1;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
