#include <stdlib.h>
#include <stdio.h>
 
void* getEIP ()
{
	return __builtin_return_address(0)-0x5;
};
 
int main(int argc, char** argv)
{
	printf("EBP located at: %p\n",getEIP());
	return 0;
}