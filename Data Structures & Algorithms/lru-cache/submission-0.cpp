class LRUCache {
public:
    struct Node 
    {
        int key;
        int val;
        Node*next;
        Node*prev;
         Node(int k,int v)
         {
            key = k;
            val = v;
            next=NULL;
            prev=NULL;
         }
    };
    int cap;
    int size=0;
    Node *dummy,*tail;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        dummy = new Node(-1,-1);
        tail = new Node(-1,-1);
        dummy->next=tail;
        tail->prev=dummy;
        cap = capacity;

    }
    void remove(Node* node)
    {
        node->next->prev=node->prev;
        node->prev->next=node->next;
        
    }
    void insertInfront(Node *node)
    {
        node->prev=dummy;
        node->next=dummy->next;
        dummy->next=node;
        node->next->prev = node;
    }
    int get(int key) {
         if(mpp.find(key)!=mpp.end())
         {
            Node* node = mpp[key];
            remove(node);
            insertInfront(node);
            return node->val;
         }
         else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* node = mpp[key];
            node->val = value;
            remove(node);
            insertInfront(node);
            return;
        }
        Node* node = new Node(key,value);
        mpp[key]=node;
        insertInfront(node);
        size++;
        if(size>cap)
        {
            Node * last=tail->prev;
            remove(last);
            mpp.erase(last->key);
            size--;
        }
    }
};
