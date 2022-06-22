class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int _key,int _value){
        key=_key;
        value=_value;
    }
};

class LRUCache {
public:
    void addnode(Node* res){
        Node* temp=head->next;
        head->next=res;
        res->next=temp;
        res->prev=head;
        temp->prev=res;
    }
    void deletenode(Node* delnode){
        Node* temp=delnode->next;
        delnode->prev->next=temp;
        temp->prev=delnode->prev;
    }
    
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key]=temp;
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==cap){
            Node* res=tail->prev;
            mp.erase(res->key);
            deletenode(res);
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
