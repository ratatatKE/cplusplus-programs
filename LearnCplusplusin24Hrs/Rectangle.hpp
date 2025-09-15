//
// Created by Moses Ndeda on 20.08.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <ios>
#include <bits/ios_base.h>

#endif //RECTANGLE_H

class Point {
    // no constructor, use default

public:
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    int getX() const { return x; }
    int getY() const { return y; }

private:
    int x;
    int y;
};


class Rectangle {
public:
    Rectangle(int newTop, int newLeft, int newBottom, int newRight);

    ~Rectangle() {
    }

    int getTop() const {
        return top;
    }
    int getLeft() const {return  left;}
    int getBottom() const {return bottom;}
    int getRight() const {return right;}

    //Notice the Point class
    Point getUpperLeft() const {return upperLeft;}
    Point getLowerLeft() const {return lowerLeft;}
    Point getUpperRight() const {return upperRight;}
    Point getLowerRight() const {return lowerRight;}

    void setUpperLeft(Point location);
    void setLowerLeft(Point location);
    void setUpperRight(Point location);
    void setLowerRight(Point location);

    void setTop (int newTop);
    void setLeft(int newLeft);
    void setBottom(int newBottom);
    void setRight(int newRight);

    int getArea() const;

    private:
    Point upperLeft;
    Point upperRight;
    Point lowerLeft;
    Point lowerRight;

    int top;
    int left;
    int bottom;
    int right;
};














































