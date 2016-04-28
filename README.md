# Type_Erasure
A C++ class that utilizes the type erasure technique

**Example Code:**

    	Object obj;
    
    	obj = 10;
    
    	auto integerVariable = obj.Get<int>();
    
    	obj = 15.0f;
    
    	auto floatVariable = obj.Get<float>();
    
    	obj = 14.6;
    
    	auto doubleVariable = obj.Get<double>();
    
    	obj = std::string("Hello!");
    
    	auto stringVariable = obj.Get<std::string>();
    	
		//In a vector container
    	std::vector<Object> objects
    	{
    		Object(std::string("This is a string!")),
    			Object(10),
    			Object(15.64f),
    			Object(45.69),
    			Object(char('A')),
    			Object(long(1254))
    	};
    
    	stringVariable = objects[0].Get<std::string>();
    	integerVariable = objects[1].Get<int>();
    	floatVariable = objects[2].Get<float>();
    	doubleVariable = objects[3].Get<double>();
    	auto charVariable = objects[4].Get<char>();
    	auto longVariable = objects[5].Get<long>();