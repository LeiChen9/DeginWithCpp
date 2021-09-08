#include<iostream>
#include<doc.h>

void Rectangle::Draw(Window* w) {
    w->DrawRect(_x0, _y0, _x1, _y1);
}