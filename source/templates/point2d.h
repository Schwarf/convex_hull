//
// Created by andreas on 11.01.22.
//

#ifndef POINT2D_H
#define POINT2D_H
#include <stdexcept>
template<class T>
class Point2D
{
public:
	Point2D() = default;
	Point2D<T>(const T & x, const T & y):x_(x), y_(y){}

	void set_x(const T & x)
	{
		x_ = x;
	}
	void set_y(const T & y)
	{
		y_ = y;
	}

	T x() const
	{
		return x_;
	}
	T y() const
	{
		return y_;
	}
	void set_point(const Point2D<T> &other) const
	{
		x_ = other.x();
		y_ = other.y();
	}

	double squared_distance_to(const Point2D &other) const
	{
		T result = (x_ - other.x()) * (x_ - other.x()) + (y_ - other.y())*(y_ - other.y());
		return static_cast<double>(result);
	}
	bool is_equal_to(const Point2D &other, const double &epsilon) const
	{
		T difference = (x_ - other.x()) + (y_ - other.y());
		if(static_cast<double>(difference) < epsilon)
			return true;
		return false;
	}

private:
	T x_;
	T y_;
};


#endif //POINT2D_H
