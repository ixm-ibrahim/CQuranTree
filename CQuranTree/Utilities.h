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
}