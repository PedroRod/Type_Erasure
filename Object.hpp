#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <memory>

class Object
{
	struct ObjectConcept
	{
	};

	template <typename T>
	struct ObjectModel : 
		ObjectConcept
	{
		explicit ObjectModel(const T& variable) :
			object(variable)
		{
		}

		T Get()
		{
			return object;
		}

	private:
		T object;
	};

	std::shared_ptr<ObjectConcept> object;

public:

	template <typename T>
	T Get()
	{
		return static_cast<ObjectModel<T>*>(object.get())->Get();
	}

	template <typename T>
	Object operator=(T variable)
	{
		Object temp(std::forward<T>(variable));
		std::swap(temp, *this);
		return *this;
	}

	template <typename T>
	explicit Object(const T& variable) :
		object(std::make_shared<ObjectModel<T>>(variable))
	{
	}

	Object() :
		object(nullptr)
	{
	}
};
#endif

