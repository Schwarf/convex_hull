//
// Created by andreas on 11.01.22.
//

#ifndef GRAHAM_SCAN_H
#define GRAHAM_SCAN_H
#include "list.h"
#include "point.h"
template <size_t dimension, class T, size_t max_list_size> class GrahamScan
{
public:
	size_t list_index_with_minimal_last_coordinate(List<Point<dimension, T>, max_list_size> & list_of_points)
	{
		size_t index_of_minimum = 0;
		T minimum = list_of_points.get(0).get_coordinate(dimension-1);
		for(size_t list_index = 1 ; list_index < max_list_size; ++list_index)
		{
			auto current_point = list_of_points.get(list_index);
			if(current_point.get_coordinate(dimension-1) < minimum)
			{
				minimum = current_point.get_coordinate(dimension-1);
				index_of_minimum = list_index;
				continue;
			}

			if(current_point.get_coordinate(dimension-1) == minimum)
			{
				for(size_t coordinate_index = dimension-2; coordinate_index > 0; --coordinate_index)
				{
					if (current_point.get_coordinate(coordinate_index) < list_of_points.get(index_of_minimum).get_coordinate(coordinate_index))
					{
						index_of_minimum = list_index;
					}
				}
			}
		}
		return index_of_minimum;
	}
};


#endif //GRAHAM_SCAN_H
