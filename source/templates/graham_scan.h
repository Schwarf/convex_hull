//
// Created by andreas on 11.01.22.
//

#ifndef GRAHAM_SCAN_H
#define GRAHAM_SCAN_H
#include "list.h"
#include "point2d.h"

template <class T>
class GrahamScan
{
public:
	template <size_t max_list_size>
	size_t list_index_for_point_with_minimal_y_coordinate(List<Point2D<T>, max_list_size> & list_of_points)
	{
		size_t index_of_minimum = 0;
		auto minimum = list_of_points.get(0).y();
		for(size_t list_index = 1 ; list_index < max_list_size; ++list_index)
		{
			auto current_point_y = list_of_points.get(list_index).y();
			if(current_point_y < minimum)
			{
				minimum = current_point_y;
				index_of_minimum = list_index;
				continue;
			}

			if(current_point_y == minimum)
			{
				if(list_of_points.get(list_index).x() < list_of_points.get(index_of_minimum).x())
				{
					index_of_minimum = list_index;
				}
			}
		}
		return index_of_minimum;
	}
};


#endif //GRAHAM_SCAN_H
