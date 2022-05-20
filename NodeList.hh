template <typename Elem>
class NodeList{
    private:
        struct Node{
        Elem elem;
        Node* prev;
        Node* next;
        };
    public:
        class Iterator
        {
        private:
            Node* v;
            
        public:
            Iterator(Node* u);
            Elem& operator*();
            bool operator==(const Iterator& p)const;
            bool operator!=(const Iterator& p)const;
            Iterator& operator++();
            Iterator& operator--();
            Iterator operator++(int);
            Iterator operator--(int);
            friend class NodeList;
        };
    public:
        NodeList();
        ~NodeList();
        int size()const;
        bool empty()const;
        Iterator begin()const;
        Iterator end()const;
        void insert(const Iterator& p, const Elem& e);
        void insertFront(const Elem& e);
        void insertBack(const Elem& e);
        void erase(const Iterator& p);
        void eraseFront();
        void eraseBack();
    private:
        int n;
        Node* header;
        Node* trailer;
};

//********************************************************************
// Funkcje klasy Iterator
template <typename Elem>
NodeList<Elem>::Iterator::Iterator(Node* u)
    { v = u; }

template <typename Elem>
Elem& NodeList<Elem>::Iterator::operator*()
    { return v->elem; }

template <typename Elem>
bool NodeList<Elem>::Iterator::operator==(const Iterator& p)const
    { return v == p.v;}

template <typename Elem>
bool NodeList<Elem>::Iterator::operator!=(const Iterator& p)const
    { return v != p.v;}

template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator++()
    { v=v->next; return *this;}

template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator--()
    { v=v->prev; return *this;}

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::Iterator::operator++(int)
{
    Iterator adres = *this;
    ++(*this);
    return adres;
}

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::Iterator::operator--(int)
{
    Iterator adres = *this;
    --(*this);
    return adres;
}

//*********************************************************************
// Funkcje klasy NodeList
template <typename Elem>
NodeList<Elem>::NodeList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

template <typename Elem>
NodeList<Elem>::~NodeList()
{
    while(!empty())
        {eraseFront();}
    delete header;
    delete trailer;
}

template <typename Elem>
int NodeList<Elem>::size()const
    {return n;}

template <typename Elem>
bool NodeList<Elem>::empty()const
    {return (n==0);}

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::begin()const
    {return Iterator(header->next);}

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::end()const
    {return Iterator(trailer);}

template <typename Elem>
void NodeList<Elem>::insert(const NodeList::Iterator& p, const Elem& e)
{
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w; w->prev = v;
    v->prev = u; u->next = v;
    n++;
}

template <typename Elem>
void NodeList<Elem>::insertFront(const Elem& e)
    {insert(begin(), e);}

template <typename Elem>
void NodeList<Elem>::insertBack(const Elem& e)
    {insert(end(), e);}

template <typename Elem>
void NodeList<Elem>::erase(const Iterator& p)
{
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w; w->prev = u;
    delete v;
    n--;
}

template <typename Elem>
void NodeList<Elem>::eraseFront()
    {erase(begin());}

template <typename Elem>
void NodeList<Elem>::eraseBack()
    {erase(end());}








