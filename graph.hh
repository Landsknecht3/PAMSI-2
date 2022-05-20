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
        std::string operator*();
        NodeList<int*>* incidentEdges();
        bool isAdjecentTo(const Vertex v)const;
};
class Edge
{
    private:
        int y;
        NodeList<Edge**> pos_Adjlist;
        Vertex **v_pos_V1;
        Vertex **v_pos_V2;
        Edge *pos_Elist;

    public:
        Edge();
        int operator*();
        NodeList<Vertex> endVertices();
        Vertex opposite(Vertex v);
        bool isAdjecentTo(const Edge f)const;
        bool isIncidentOn(const Vertex v)const;
        friend class Vertex;
};
class Graph : public Vertex{
    public:
        NodeList<Vertex> Vertices;
        NodeList<Edge> Edges;
        friend class Vertex;
        friend class Edge;
};

//***********************************
// Funkcje klasy Vertex
 


 //***********************************
 // Funkcje klasy Edge


 //***************************************
 // Funkcje klasy Graph