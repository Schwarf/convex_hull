#include <iostream>
#include "list.h"
#include "point2d.h"
#include "graham_scan.h"



int main()
{
	List<Point2D<int>, 3> list{};
	Point2D<int> point(1,2);

	Point2D<int> point2(1,3);
	Point2D<int> point3(1,4);
	list.add(point3);
	list.add(point);
	list.add(point2);
	GrahamScan<int> g;

	std::cout << "INdex = " << 	g.list_index_for_point_with_minimal_y_coordinate<3>(list) << std::endl;
	std::cout << point.is_equal_to(point3, 1e-8) << std::endl;
	std::cout << point3.squared_distance_to(point) << std::endl;
	list.add(point);
	return 0;
}
