/**
思路:1.判断|AP|+|PB|=|AB|?
思路:2.通过向量叉积判断，点在线段上<=>向量AP×向量AB=0，并且点P坐标在AB坐标之间
**/

//方法1
int PointIsOnSegment(Point P, Point A, Point B)
{
    double d1 = DistanceOfPoints(P, A);
    double d2 = DistanceOfPoints(P, B);
    double d3 = DistanceOfPoints(A, B);

    if (d1 + d2 == d3)
        return 1;
    else
        return 0;
}

//方法2
/* 点是否在线段上: 向量判断 */
int PointIsOnSegment(Point P, Point A, Point B)
{
    Vector AP = VectorConstruct(P, P);
    Vector AB = VectorConstruct(A, B);

    // 两向量不平行
    if (CrossProduct(AP, AB) == 0 &&
        P.x >= Min(A.x, B.x) && P.x <= Max(A.x, B.x) &&
        P.y >= Min(A.y, B.y) && P.y <= Max(A.y, B.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
其中

/*
 * 由两个点构造一个向量
 */
Vector VectorConstruct(Point A, Point B)
{
    Vector v;
    v.x = B.x - A.x;
    v.y = B.y - A.y;
    return v;
}

// 向量的叉积
double CrossProduct(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}
