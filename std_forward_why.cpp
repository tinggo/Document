#include <type_traits>

class Test
{
public:
	Test()
		:a( 0 ), b( 0 ), c( 0 )
	{}

	Test( const Test& p )
	{
		a = p.a;
		b = p.b;
		c = p.c;
	}

	Test( const Test&& p )
	{
		a = p.a + 1;
		b = p.b + 1;
		c = p.c + 1;
	}

	int a;
	int b;
	int c;
};

template<typename T>
void ForwardTest( T&& t )
{
	// See the difference that the first one calls constructor and
	// the latter one calls move constructor.	
	T copy1( t );
	T copy2( std::forward<T>(t) );
}

int main()
{
	// Test() is rvalue for sure at this point.
	ForwardTest(Test());
	return 0;
}