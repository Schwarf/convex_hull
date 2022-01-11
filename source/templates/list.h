//
// Created by andreas on 11.01.22.
//

#ifndef LIST_H
#define LIST_H

template <class T, size_t max_size>
class List{
public:
	List<T, max_size>(){
		max_size_ = max_size;
		size_ = 0;
		elements_ = new T[max_size];
	};

	bool add(T element)
	{
		if(size_ < max_size_) {
			elements_[size_] = element;
			size_++;
			return true;
		}
		return false;
	}

	T get(size_t index)
	{
		if(index >= size_)
			return T{};
		return elements_[index];
	}

	size_t size()
	{
		return size_;
	}

	bool replace(T element, size_t index)
	{
		if(index < size_)
		{
			elements_[index] = element;
			return true;
		}
		return false;
	}

private:
	size_t size_;
	size_t max_size_;
	T* elements_;
};

#endif //LIST_H
