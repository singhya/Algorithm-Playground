class LRUCache : public Cache{
    public:
    LRUCache(int capacity)
    {
        cp = capacity;  
        tail = NULL;
        head = NULL;
    }
    int get(int key)
    {
        Node* iterator = head;
        bool found = false;
        while(iterator)
        {
            if(iterator->key==key)
            {
                return iterator->value;
                break;
            }
            iterator=iterator->next;
        }
        return -1;
    }
    void set(int key, int value)
    {
        Node* iterator = head;
        bool found = false;
        while(iterator)
        {
            if(iterator->key==key)
            {
                cout<<iterator->value<<endl;
                found = true;
                break;
            }
            iterator=iterator->next;
        }
        if(!found)
        {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->key=key;
            new_node->value = value;
            new_node->prev = NULL;
            new_node->next = head;
            head = new_node;
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            Node* pr = iterator->prev;
            pr->next = iterator->next;
            iterator->next = head;
            head->prev = iterator;
            head = iterator;
        }
    }
};
    
