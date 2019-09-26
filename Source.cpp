#include <stdio.h>

class Point {
public:
    Point() = default;
    Point(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }

    int distance()
    {
        return (this->X < 0 ? this->X * -2 : this->X * 2);
    }

    void readPoint()
    {
        printf("Enter X and Y coordinates: ");
        scanf("%d%d", &this->X, &this->Y);
    }

    void displayPoint()
    {
        printf("Coordinates of the given point are: %d %d\n", this->X, this->Y);
    }
    static Point middle(Point *a, Point *b)
    {
        Point result;
        result.X = (a->X + b->X) / 2;
        result.Y = (a->Y + b->Y) / 2;
        return result;
    }
    static Point addPoints(Point *a, Point *&b)
    {
        Point result;
        result.X = a->X + b->X;
        result.Y = a->Y + b->Y;
        return result;
    }
    ~Point()
    {
        delete this;
    }
private:
    int X;
    int Y;
};

int main()
{
    Point *p1 =  new Point(1, 2);
    Point *p2 = new Point(3,4);
    p1->displayPoint();
    p2->displayPoint();
    printf("Distant to p1 symmetrical point = %d\n", p1->distance());
    printf("Distant to p2 symmetrical point = %d\n", p2->distance());
    Point mid = Point::middle(p1, p2);
    printf("Middle point:\n");
    mid.displayPoint();
    Point result = Point::addPoints(p1, p2);
    printf("Sum of p1 and p2:\n");
    result.displayPoint();
    printf("Distant to p1 + p2 symmetrical point = %d\n", result.distance());
    //delete p1, p2;
    return 0;
}