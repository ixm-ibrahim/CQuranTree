#pragma once

#include <algorithm>
#include <vector>

namespace Utilities
{
	template <class T>
	bool equals(std::vector<T> a, std::vector<T> b)
	{
		if (a.size() != b.size())
			return false;
		
		for (unsigned int i = 0; i < a.size(); i++)
			if (a[i] != b[i])
				return false;

		return true;
	}
	
	template <class T>
	int index_of(std::vector<T> vec, T elem)
	{
		for (unsigned int i = 0; i < vec.size(); i++)
			if (vec[i] == elem)
				return i;

		return -1;
	}
	
	template <class T>
	int index_of(std::vector<T*> vec, T elem)
	{
		for (unsigned int i = 0; i < vec.size(); i++)
			if (*vec[i] == elem)
				return i;

		return -1;
	}
	
	template <class T>
	int occurance_of(std::vector<T> vec, T elem)
	{
		return std::count(vec.begin(), vec.end(), elem);
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

	template <class T>
	int closest_value_lower(const std::vector<T>& vec, T value)
	{
		auto const it = std::lower_bound(vec.begin(), vec.end(), value);
		if (it == vec.end()) { return -1; }

		return *it;
	}
	
	template <class T>
	int index_of_closest_value_lower(const std::vector<T>& vec, T value)
	{
		auto const it = std::lower_bound(vec.begin(), vec.end(), value);
		if (it == vec.end()) { return -1; }

		return it - vec.begin();
	}

	template <class T>
	int closest_value_upper(const std::vector<T>& vec, T value)
	{
		auto const it = std::upper_bound(vec.begin(), vec.end(), value);
		if (it == vec.end()) { return -1; }

		return *it;
	}

	template <class T>
	int index_of_closest_value_upper(const std::vector<T>& vec, T value)
	{
		auto const it = std::upper_bound(vec.begin(), vec.end(), value);
		if (it == vec.end()) { return -1; }

		return it - vec.begin();
	}
}