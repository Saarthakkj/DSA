struct node{
    int key ;
    int val ;
    int freq ; 
    node* next; 
    node* prev ;
    node(int x , int y ){
        freq = 1 ;
        key = x ;
        val =  y;
        next =  nullptr;
        prev = nullptr;
    }
};
struct List{
    int size; 
    node* head ;
    node* tail ; 
    List(){
        head = new node(-1, -1); 
        tail = new node(-1,-1); 
        head->next = tail ;
        tail->prev = head ;
        size = 0 ;
    }
    void addtofront(node* curr){
        curr->next = head->next ;
        head->next->prev = curr;
        curr->prev = head;
        head->next = curr;
        size++; 
    }
    void removenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        //cout<< "delnode: "<< delnode->val << "delnode prev : " << delnode->prev->val ; 
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    };
};
class LFUCache {
    int min_freq ;
    map<int , node*> keynode ; 
    map< int,  List*> freqlist ; 

    int cap = 0 ;
    //this cap is of keynode

    int max_cap ;

public:
    LFUCache(int capacity) {
        max_cap = capacity ;
        min_freq = 0 ; 
        cap = 0; 
    }
    void updatefreqlistmap(node *curr){
        keynode.erase(curr->key);
        //remove the node from the cooresponding frequency list: 
        //cout<< "curr is: "<< curr->val << endl;
        freqlist[curr->freq]->removenode(curr);

        //check if the node deleted was the min freq node
        if(curr->freq == min_freq){
            //check if last node or not
            //cout<< "curr->freq : "<< curr->freq ;
            if(freqlist[curr->freq]->size == 0 ){
                //true than 
                //cout<< "min _freq here : "<< min_freq << endl;
                min_freq++ ;
                //cout<< "min _freq here2: "<< min_freq << endl;
            }
        }

        //now add the current node into the new list
        int new_freq = curr->freq + 1; 

        List* higher_freq_list = new List();

        //check if the higher node freq exist or not
        if(freqlist.find(new_freq) != freqlist.end()){
            //list already exist
            higher_freq_list =  freqlist[new_freq] ;
        }

        //add the curr to this new list
        higher_freq_list->addtofront(curr);
        curr->freq++;
        freqlist[new_freq] =  higher_freq_list;
        //update also in keynode
        keynode[curr->key] = curr;

    }
   
    
    int get(int key) {
        if(keynode.find(key) == keynode.end()){
            //doesn't exist
            return -1;
        }
        else{
            node* curr = keynode[key];
            updatefreqlistmap(curr);
            return curr->val ; 
        }
    }
    
    void put(int key, int value) {
        if(max_cap  == 0 ){
            return ;
        }
        if(keynode.find(key) != keynode.end()) {
            node* curr = keynode[key]; 
            curr->val = value; 
            updatefreqlistmap(curr); 
        }
        else{
            if(cap == max_cap){
                //remove lru 
                //that is list->tail->prev
                //cout<< " min freq is: "<< min_freq << endl;
                List* del_list =  freqlist[min_freq];
                //cout<< "key and value is : "<< key << " " <<  value << endl;
                //cout<< "head->next->val : "<< del_list->head->next -> val << endl;
                keynode.erase(del_list->tail->prev->key);
                node* del_node = del_list->tail->prev ; 
                //cout<< "del_node  : "<< del_node->val << endl;
                del_list->removenode(del_node); 
                cap --  ;
            }
            cap ++; 
            min_freq = 1 ; 
            List* one_freq = new List();
            //not found , put it in freq = 1 list 
            if(freqlist.find(min_freq) != freqlist.end()){
                one_freq = freqlist[min_freq] ;
            }
            node* curr = new node(key , value);
            one_freq->addtofront(curr);
            freqlist[min_freq] = one_freq ; 
            keynode[key] = curr ; 
        } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 