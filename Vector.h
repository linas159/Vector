#pragma once
#include <iostream>

template <typename T>
class Vector
{
public:
	//MEMBER FUNCTIONS
	Vector() :sz(0), cap(5), arr(new T[cap]){};
	Vector(const Vector& rhs) :sz(rhs.sz), cap(rhs.cap), arr(new T[cap])
	{
		for (int i = 0; i < rhs.size(); ++i)
		{
			arr[i] = rhs.arr[i];
		}
	}
	Vector(int elements, int value = 0) :sz(elements), cap(elements+5), arr(new T[cap])
	{
		for (int i = 0; i < sz; ++i)
		{
			arr[i] = value;
		}
	}
	Vector(const std::initializer_list<T>& list) :sz(), cap(list.size() + 5), arr(new T[cap])
	{
		for (T i : list)
		{
			push_back(i);
		}
	}

	~Vector() 
	{
		delete[] arr;
	};

	Vector& operator= (const Vector& rhs)
	{
		if (rhs.sz >sz) 
		{
			delete[] arr;
			cap = rhs.sz + 5;
			arr = new T[cap];
		}
		for (int i = 0; i < rhs.sz; ++i)
		{
			arr[i] = rhs.arr[i];
		}
		sz = rhs.sz;
		return *this;
	}

	//ELEMENT ACCESS
	T& at(int index)
	{
		return arr[index];
	}
	T& operator[] (int index)
	{
		return arr[index];
	}
	T& front()
	{
		return arr[0];
	}
	T& back()
	{
		return arr[sz - 1];
	}
	T& data()
	{
		return arr;
	}

	//ITERATORS
	int begin()
	{
		return arr[0];
	}
	int end()
	{
		return arr[sz - 1];
	}
	int rbegin()
	{
		return arr[sz - 1];
	}
	int rend()
	{
		return arr[0];
	}

	//CAPACITY
	bool empty() 
	{
		return sz == 0;
	};
	int size()
	{
		return sz;
	};
	long long int max_size()
	{
		return pow(2, 32);
	}
	void reserve(int max_elements)
	{
		while (cap < max_elements)
		{
			cap *= 2;
		}
	}
	int capacity()
	{
		return cap;
	};
	void shrink_to_fit()
	{
		cap = sz;
		T* newarr = new T[cap];
		for (int i = 0; i < sz; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}

	//MODIFIERS
	void clear()
	{
		sz = 0;
	}
	void insert(int index, T value)
	{
		if (sz != cap)
		{
			for (int i = sz - 1; i >= index; --i)
			{
				arr[i + 1] = arr[i];
			}
			arr[index] = value;
			++sz;
		}
		else
		{
			cap *= 2;
			T* newarr = new T[cap];
			for (int i = 0; i < sz; i++)
			{
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			insert(index, value);
		}
	}
	void emplace(int index, T value)
	{
		if (sz != cap)
		{
			for (int i = sz - 1; i >= index; --i)
			{
				arr[i + 1] = arr[i];
			}
			arr[index] = value;
			++sz;
		}
		else
		{
			cap *= 2;
			T* newarr = new T[cap];
			for (int i = 0; i < sz; i++)
			{
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			insert(index, value);
		}
	}
	void erase(int index)
	{
		for (int i = index; i < sz - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		--sz;
	}
	void push_back(T value)
	{
		if (sz < cap)
		{
			arr[sz] = value;
			++sz;
		}
		else
		{
			cap *= 2;
			T* newarr = new T[cap];
			for (int i = 0; i < sz; i++)
			{
				newarr[i] = arr[i];
			}
			newarr[sz] = value;
			++sz;
			delete[] arr;
			arr = newarr;
		}
	};
	void emplace_back(T value)
	{
		if (sz < cap)
		{
			arr[sz] = value;
			++sz;
		}
		else
		{
			cap *= 2;
			T* newarr = new T[cap];
			for (int i = 0; i < sz; i++)
			{
				newarr[i] = arr[i];
			}
			newarr[sz] = value;
			++sz;
			delete[] arr;
			arr = newarr;
		}
	};
	void pop_back()
	{
		--sz;
	}
	void resize(int size)
	{
		int oldsz;
		if (sz < cap)
		{
			oldsz = sz;
			sz = size;
			for (int i = oldsz; i < sz; i++)
			{
				arr[i] = 0;
			}
		}
		else
		{
			cap *= 2;
			oldsz = sz;
			sz = size;
			for (int i = oldsz; i < sz; i++)
			{
				arr[i] = 0;
			}
		}
	}
	void resize(int size,T value)
	{
		int oldsz;
		if (sz < cap)
		{
			oldsz = sz;
			sz = size;
			for (int i = oldsz ; i < sz; i++)
			{
				arr[i] = value;
			}
		}
		else
		{
			cap *= 2;
			oldsz = sz;
			sz = size;
			for (int i = oldsz; i < sz; i++)
			{
				arr[i] = value;
			}
		}
	}
	void swap(Vector &newvec)
	{
		T* newarr = new T[cap];
		for (int i = 0; i < sz; i++)
		{
			newarr[i] = arr[i];
		}
		int newsz = sz;
		int newcap = cap;
		sz = newvec.sz;
		cap = newvec.cap;
		for (int i = 0; i < sz; i++)
		{
			arr[i] = newvec.arr[i];
		}
		newvec.sz = newsz;
		newvec.cap = cap;
		for (int i = 0; i < newvec.sz; i++)
		{
			newvec.arr[i] = newarr[i];
		}
	}

	//NON-MEMBER FUNCTIONS
	bool operator==(const Vector& rhs)
	{
		if (size() != rhs.size())
			return false;
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] != rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	};
	bool operator!=(const Vector& rhs)
	{
		return!(*this == rhs);
	}
	bool operator<(const Vector& rhs)
	{
		if (size() != rhs.size())
			return false;
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] >= rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	};
	bool operator<=(const Vector& rhs)
	{
		if (size() != rhs.size())
			return false;
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] > rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	};
	bool operator>(const Vector& rhs)
	{
		if (size() != rhs.size())
			return false;
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] <= rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	};
	bool operator>=(const Vector& rhs)
	{
		if (size() != rhs.size())
			return false;
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] < rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	};
	friend std::ostream& operator<< (std::ostream& ostr, const Vector& rhs)
	{
		for (int i = 0; i < rhs.sz; ++i)
		{
			ostr << rhs.arr[i] << " ";
		}
		return ostr;
	};

private:
	int sz;
	int cap;
	T* arr;
};
