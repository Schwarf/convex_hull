//
// Created by andreas on 11.01.22.
//

#ifndef POINT2D_H
#define POINT2D_H
template<class T>
class Point2D
{
public:
	Point2D<T>() = default;
	Point2D<T>(const T &x, const T &y)
		: x_(x), y_(y)
	{

	}
	void set_x(const T &x)
	{
		x_ = x;
	}
	void set_y(const T &y)
	{
		y_ = y;
	}
	void set_point(const Point2D<T> &other)
	{
		this->x_ = other.x();
		this->y_ = other.y();
	}
	T x()
	{
		return x_;
	}

	T y()
	{
		return y_;
	}

	double squared_distance_to(const Point2D<T> &other)
	{
		T result = (x_ - other.x()) * (x_ - other.x()) + (y_ - other.y()) * (y_ - other.y());
		return static_cast<double>(result);
	}
	bool is_equal_to(const Point2D<T> &other, const double &epsilon)
	{
		T diff = (x_ - other.x()) + (y_ - other.y());
		double difference = std::abs(static_cast<double>(diff));
		if (difference < epsilon)
			return true;
		return false;
	}


private:
	T x_{};
	T y_{};
};


#endif //POINT2D_H
