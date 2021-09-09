#ifndef _GRAPH_
#define _GRAPH_

class Graphic{
    virtual void Draw();
    virtual void Add(Graphic*);
    void Remove(Graphic*);
    void GetChild(int);
};


#endif