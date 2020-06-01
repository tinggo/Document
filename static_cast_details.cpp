// This explained https://stackoverflow.com/questions/6260989/when-do-casts-call-the-constructor-of-the-new-type
class T2;

class T1
{
public:
	// This function is not called in this case.
	operator T2()
	{
		return T2();
	}
};

class T2
{
public:
	T2() = default;
	T2(T1&)
	{

	}
};

int main()
{
	T1 t;
	T2 t2 = (T2)t;
	return 0;
}
