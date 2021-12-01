#pragma once

#include <vector>

namespace Utilities
{
	template <class T>
	int index_of(std::vector<T> vec, T elem)
	{
		for (unsigned int i = 0; i < vec.size(); i++)
			if (vec[i] == elem)
				return i;

		return -1;
	}

	template <class T>
	void addrange(std::vector<T>& vec, std::vector<T> appending)
	{
		vec.insert(vec.end(), appending.begin(), appending.end());
	}

	template <class T>
	void insert_at(std::vector<T>& vec, int in, T elem)
	{
		vec.insert(vec.begin() + in, elem);
	}

	template <class T>
	void remove_at(std::vector<T>& vec, int in)
	{
		vec.erase(vec.begin() + in);
	}

	template <class T>
	void remove_all(std::vector<T>& vec, T elem)
	{
		vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
	}
}