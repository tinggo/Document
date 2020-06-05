/*
** Small tip
** This is a tip in Visual Studio, print the log as following enable you to click the line 
** in output window and navigates to the source code automatically in Visual Studio.
*/

#include <cstdio>
#include <windows.h>

int main()
{
	char buffer[1024];
	sprintf( buffer, "\t%s(%d)\n", __FILE__, __LINE__ );
	OutputDebugStringA( buffer );
	return 0;
}
