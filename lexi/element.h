#include<iostream>

using namespace std;

typedef float Coord;
class Point{
public:
    static const Point Zero;

    Point(Coord x = 0.0, Coord y = 0.0);

    Coord X() const; void X(Coord x);
    Coord Y() const; void Y(Coord y);

    friend Point operator+ (const Point&, const Point&);
    friend Point operator- (const Point&, const Point&);
    friend Point operator* (const Point&, const Point&);
    friend Point operator/ (const Point&, const Point&);

    Point& operator+= (const Point&);
    Point& operator-= (const Point&);
    Point& operator*= (const Point&);
    Point& operator/= (const Point&);

    Point operator-();

    friend bool operator== (const Point&, const Point&);
    friend bool operator!= (const Point&, const Point&);

    friend ostream& operator<< (ostream&, const Point&);
    friend istream& operator>> (istream&, Point&);
};

class Rect {
public:
    static const Rect Zero;

    Rect(Coord x, Coord y, Coord w, Coord h);
    Rect(const Point& origin, const Point& extent);

    Coord Width() const; void Width(Coord);
    Coord Height() const; void Height(Coord);
    Coord Left() const; void Left(Coord);
    Coord Bottom() const; void Bottom(Coord);

    Point& Origin() const; void Origin(const Point&);
    Point& Extent() const; void Extent(const Point&);

    void MoveTo(const Point&);
    void MoveBy(const Point&);

    bool IsEmpty() const;
    bool Contains(const Point&) const;
};

class Window {
public:
    void DrawRect(int, int, int, int);
};