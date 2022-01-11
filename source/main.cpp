#include <iostream>
#include "list.h"
#include "point.h"
#include "graham_scan.h"


using Point2D = Point<2,int>;
int main()
{
	List<Point2D, 3> list{};
	Point<2,int> point;
	point.set_coordinate(0, 1);
	point.set_coordinate(1, 2);
	Point<2,int> point2;
	point2.set_coordinate(0, 1);
	point2.set_coordinate(1, 3);
	Point<2,int> point3;
	point3.set_coordinate(0, 1);
	point3.set_coordinate(1, 4);
	list.add(point3);
	list.add(point2);
	list.add(point);
	GrahamScan<2, int ,3> g;

	std::cout << "INdex = " << 	g.list_index_with_minimal_last_coordinate(list) << std::endl;
	std::cout << point.is_equal_to(point3, 1e-8) << std::endl;
	std::cout << point3.squared_distance_to(point) << std::endl;
	list.add(point);
	return 0;
}
