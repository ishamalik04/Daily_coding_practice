class Node
{
    public:
    int key,value,cnt;
    Node*next;
    Node*prev;
    Node(int _key,int _value)
    {
        key=_key;
        value=_value;
        cnt=1;
    }
};
 class List
{
    public:
    int size;
    Node*head,*tail;
    List()
    {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addFront(Node*node)
    {
        Node*temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }

    void removeNode(Node*delnode)
    {
        Node*delPrev=delnode->prev;
        Node*delNext=delnode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }

};
class LFUCache {
public:
    map<int,Node*>keyNode;
    map<int,List*>freqListMap;
    int maxSize,minFreq,currSize;
    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        currSize=0;
    }

    void updateFreqListMap(Node*node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0)
        {
            minFreq++;
        }
        List*nextHighFreq=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end())
        {
            nextHighFreq=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHighFreq->addFront(node);
        freqListMap[node->cnt]=nextHighFreq;
        keyNode[node->key]=node;
    }

    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node*node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(maxSize==0)
        {
            return;
        }
        if(keyNode.find(key)!=keyNode.end())
        {
            Node*node=keyNode[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else
        {
            if(currSize==maxSize)
            {
                List*list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List*listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end())
            {
                listFreq=freqListMap[minFreq];
            }
            Node *node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
