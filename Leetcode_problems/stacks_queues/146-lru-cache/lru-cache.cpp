class LRUCache {
public:
    //make a doubly linkedlist
    class node{
        public: 
            int key ;
            int val ;
            node* next ;
            node* prev ;
        node(int k , int v){
            key = k ;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    // Helper function to add a node to the front
    void addToFront(node* current) {
        current->next = head->next;
        head->next->prev = current;
        head->next = current;
        current->prev = head;
    }

    // Helper function to remove a node from the list
    void removeNode(node* current) {
        current->prev->next = current->next ;
        current->next->prev = current->prev ;
    }
    
    unordered_map<int , node* > mpp ; 
    int cap = 0 ;
    int max_cap ;
    node* head = new node(-1 , -1 ); 
    node* tail = new node(-1 , -1) ; 

    LRUCache(int capacity) {
        max_cap = capacity ;
        head -> next = tail ;
        tail->prev = head ; 
    }
    
    int get(int key) {
        //cout<< "key is : " << key << "mpp[key]: "<< (*mpp[key]).val<< endl;
        if(mpp.find(key) == mpp.end() ){
            //cout<< "here";
            return -1;
        }else{
           // cout<< "*mpp[key]" << mpp[key]->val ;
            int value = mpp[key]->val ;
            removeNode(mpp[key]) ;
            //now make the new node 
            node* new_node = new node(key , value);
            addToFront(new_node);
            mpp[key] = new_node ; 
        }
        return (mpp[key]->val) ;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) 
        {
            // Key exists, update value
            mpp[key]->val = value;
            removeNode(mpp[key]);
            addToFront(mpp[key]);
        }
        else {
            // Key doesn't exist, insert new node
            node* newNode = new node(key, value);
            mpp[key] = newNode;
            addToFront(newNode);
            // cout<< "added to front is : "<< key << " "<< value << endl;
            // cout<< "value in map: "<< (*mpp[key]).val  << endl;

            if (mpp.size() > max_cap) {
                //cout<<  "this is executed on "<< key << endl;
                // Remove the least recently used node
                node* toDelete = tail->prev;
                mpp.erase(toDelete->key);
                removeNode(toDelete);
                delete toDelete;
            }
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */