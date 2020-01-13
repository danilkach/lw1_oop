#include <stdio.h>

class Point {
public:
    Point() = default;
    Point(int x, int y)
    : X(x), Y(y) {}
    void init(int x, int y)
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
    int getX() { return this->X; }
    int getY() { return this->Y; }
    void displayPoint()
    {
        printf("Coordinates of the given point are: %d %d\n", this->X, this->Y);
    }
    static Point middle(Point a, Point b)
    {
        Point result;
        result.X = (a.X + b.X) / 2;
        result.Y = (a.Y + b.Y) / 2;
        return result;
    }
    static Point addPoints(Point a, Point b)
    {
        Point result;
        result.X = a.X + b.X;
        result.Y = a.Y + b.Y;
        return result;
    }
    ~Point() {}
protected:
    int X;
    int Y;
};

class Point3 : Point {
    Point3& operator=(Point b)
    {
        this->X = b.getX();
        this->Y = b.getY();
        this->Z = b.distance() / 2;
    }
    Point3(int x, int y, int z)
    {
        Point(x, y);
        this->Z = z;
    }
    void Init(int x, int y, int z)
    {
        init(x, y);
        this->Z = z;
    }
    void displayPoint()
    {
        printf("Coordinates of the given point are: %d %d %d\n", this->X, this->Y, this->Z);
    }
    int distance()
    {
        return (this->X - this->Y - this->Z);
    }
public:
    int getZ() { return this->Z; }
    void setZ(int value) { this->Z = value; }
private:
    int Z;
};

int main()
{
    int n = 2;
    Point *p = new Point[n];
    p[0].init(1,2);
    p[1].init(3, 4);
    p[0].displayPoint();
    p[1].displayPoint();
    printf("Distant to p1 symmetrical point = %d\n", p[0].distance());
    printf("Distant to p2 symmetrical point = %d\n", p[1].distance());
    Point mid = Point::middle(p[0], p[1]);
    printf("Middle point:\n");
    mid.displayPoint();
    Point result = Point::addPoints(p[0], p[1]);
    printf("Sum of p1 and p2:\n");
    result.displayPoint();
    printf("Distant to p1 + p2 symmetrical point = %d\n", result.distance());
    delete[] p;
    return 0;
}