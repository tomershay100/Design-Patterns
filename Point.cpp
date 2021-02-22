#include <vector>
#include <iostream>

//
// Created by tomer on 17-Feb-21.
//
using namespace std;

class Point;
static vector<Point *> points;
class Point {
    int _x, _y;
    int countPointers;

    Point(int x, int y) {
        _x = x;
        _y = y;
        countPointers = 0;
    }


public:

    ~Point() {
        //delete this;
    };

    Point *setX(int x) const {
        return newPoint(x, _y);
    }

    Point *setY(int y) const {
        return newPoint(_x, y);
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }

    static Point *newPoint(int x, int y) {
        for (auto &point : points) {
            if (point != nullptr) {
                if (*point == Point(x, y)) {
                    point->countPointers++;
                    return point;
                }
            }
        }
        auto *p = new Point(x, y);
        points.push_back(p);
        p->countPointers++;
        return p;
    }

    static void delPoint(Point *p) {
        for (auto &point : points) {
            if (point == p) {
                if (point->countPointers == 1)
                    point = nullptr;
                else
                    point->countPointers--;
            }
        }
    }

    static void clearAll() {
        points.clear();
    }

    bool operator==(const Point &p) const {
        return _x == p._x && _y == p._y;
    }
};

int main() {
    Point *p1 = Point::newPoint(10, 20);
    Point *p2 = Point::newPoint(10, 20);
    cout << (p1 == p2) << endl;

    Point::delPoint(p1);
    cout << (p1 == nullptr) << endl;
    cout << p2->getX() << ", " << p2->getY() << endl;
    Point::delPoint(p2);

    Point *p3 = Point::newPoint(11, 4);
    Point *p4 = Point::newPoint(11, 4);
    cout << (p3 == p4) << endl; //true

    p4 = p4->setX(10);
    cout << p4->getX() << ", " << p4->getY() << endl;
    cout << p3->getX() << ", " << p3->getY() << endl;
    cout << (p3 == p4) << endl; //false
    p3 = p3->setX(10);
    cout << (p3 == p4) << endl; //true

    Point::clearAll();
}
