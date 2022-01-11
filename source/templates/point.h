//
// Created by andreas on 11.01.22.
//

#ifndef POINT_H
#define POINT_H
#include <stdexcept>
template<size_t dimension, class T>
class Point
{
public:
	Point<dimension, T>()
		: dimension_(dimension)
	{}

	bool set_coordinate(size_t index, const T &value)
	{
		if (index < dimension) {
			coordinates_[index] = value;
			return true;
		}
		return false;
	}
	void set_point(const Point<dimension, T> &other)
	{
		for (size_t index = 0; index < dimension_; ++index) {
			this->coordinates_[index] = other.get_coordinate(index);
		}
	}

	T get_coordinate(size_t index) const
	{
		if (index >= dimension_)
			std::out_of_range("Index in 'get_coordinate' is out of range!");
		return coordinates_[index];
	}

	double squared_distance_to(const Point<dimension, T> &other) const
	{
		T result{};
		for (size_t index = 0; index < dimension_; ++index) {
			result += (get_coordinate(index) - other.get_coordinate(index))
				* (get_coordinate(index) - other.get_coordinate(index));
		}
		return static_cast<double>(result);
	}
	bool is_equal_to(const Point<dimension, T> &other, const double &epsilon) const
	{
		T diff{};
		for (size_t index = 0; index < dimension_; ++index) {
			diff += (get_coordinate(index) - other.get_coordinate(index))
				* (get_coordinate(index) - other.get_coordinate(index));
		}
		double difference = std::abs(static_cast<double>(diff));
		if (difference < epsilon)
			return true;
		return false;
	}


private:
	T coordinates_[dimension];
	size_t dimension_;
};


#endif //POINT_H
