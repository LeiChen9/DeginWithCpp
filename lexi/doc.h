#ifndef _DOC_
#define _DOC_

#include <element.h>

class Glyph {
public:
    virtual void Draw(Window* );
    virtual void Bound(Rect* );
    virtual void Intersects(const Point&);
    virtual void Insert(Glyph*, int);
    virtual void Remove(Glyph*);
    virtual Glyph* Child(int);
    virtual Glyph* Parent();
};

class Rectangle: public Glyph{
public:
    void Draw(Window*);
private:
    int _x0, _y0, _x1, _y1;
};

#endif