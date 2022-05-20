#include "iostream"
#include "string"
#include "NodeList.hh"

class Edge;

class Vertex{

    private:
        std::string x;        
        NodeList<Edge*> Adj_list;
        Vertex *pos_Vlist;
    public:
        friend class Edge;
        Vertex();
        ~Vertex();
        Vertex(std::string x);
        std::string operator*();
};
class Edge
{
    private:
        int y;
        Edge** pos_Adjlist_1;
        Edge** pos_Adjlist_2;
        Vertex **v_pos_V1;
        Vertex **v_pos_V2;
        Edge *pos_Elist;

    public:
        friend class Vertex;
        Edge();
        Edge(Vertex &v, Vertex &w, int y);
        ~Edge();
        int operator*();
};
class Graph : public Vertex{
    private:
        NodeList<Vertex> Vertices;
        NodeList<Edge> Edges;
    public:
        friend class Vertex;
        friend class Edge;
        Graph();
        NodeList<Vertex> endVertices(Edge& e);
        Vertex opposite(Vertex &v, Edge &e);
        bool areAdjecent(Vertex &v, Vertex &w);
        void replace(Vertex &v, std::string x);
        void replace(Edge &e, int y);
        void insertVertex(std::string x);
        void insertEdge(Vertex &v, Vertex &w, int y);
        void removeVertex(Vertex &v);
        void removeEdge(Edge &e);
        NodeList<Edge> incedentEdges(Vertex &v);
        NodeList<Vertex> vertices();
        NodeList<Edge> edges();
};

//***********************************
// Funkcje klasy Vertex

Vertex::Vertex()
    {x = "NULL"; pos_Vlist=nullptr;}

Vertex::~Vertex()
    {delete pos_Vlist; Adj_list.~NodeList();}

Vertex::Vertex(std::string x)
    {this->x=x; pos_Vlist=nullptr;}

std::string Vertex::operator*()
    {return x;}

 //***********************************
 // Funkcje klasy Edge
Edge::Edge()
    {y=0; pos_Elist=nullptr;
    v_pos_V1=nullptr; v_pos_V2=nullptr;
    pos_Adjlist_1=nullptr; pos_Adjlist_2=nullptr;}

Edge::Edge(Vertex &v, Vertex &w, int y)
    {this->y=y; pos_Elist=nullptr;
    v.Adj_list.insertFront(this); w.Adj_list.insertFront(this);
    v_pos_V1=&(v.pos_Vlist); v_pos_V2=&(w.pos_Vlist);
    pos_Adjlist_1=&*(v.Adj_list.begin()); pos_Adjlist_2=&*(w.Adj_list.begin());
    }

Edge::~Edge()
    {delete pos_Elist;
    delete v_pos_V1; delete v_pos_V2;
    delete pos_Adjlist_1; delete pos_Adjlist_2;}
int Edge::operator*()
    {return y;}
 //***************************************
 // Funkcje klasy Graph