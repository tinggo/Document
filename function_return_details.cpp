class Test
{
public:
	Test() {}
	Test( Test& ) {}
	Test( Test&& ) {}
	Test& operator=( Test& ) {}
	Test& operator=( Test&& ) {}
	~Test() {}
};

class Test2
{
public:
	Test2() {}
	Test2( Test2& ) {}	
	Test2& operator=( Test2& ) {}	
	~Test2() {}
};

Test case0() 
{
	return Test();	
}

Test case1()
{
	Test t = Test();
	return t;
}

Test2 case2()
{
	return Test2();
}

Test2 case3()
{
	Test2 t2 = Test2();
	return t2;
}

int main()
{
	case0();
	// constructor -> destroy
	case1();
	// constructor -> move constructor -> destroy -> destroy
	case2();
	// constructor -> destroy
	case3();
	// constructor -> copy constructor -> destroy -> destroy

	Test t1 = case0();
	// constructor
	Test t2 = case1();
	// constructor -> move constructor -> destroy
	Test2 t3 = case2();
	// constructor
	Test2 t4 = case3();
	// constructor -> copy constructor -> destroy
	return 0;
}