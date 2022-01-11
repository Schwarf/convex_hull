#include <iostream>
#include "list.h"
#include "point2d.h"

int main()
{
	List<Point2D<int>, 5> list{};
	Point2D<int> point(1,2);

	list.add(point);
	return 0;
}
