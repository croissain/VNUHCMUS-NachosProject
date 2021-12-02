#include "syscall.h"
#include "copyright.h"

#define MAX_LENGTH 255
int main()
{
	PrintString("===CHUONG TRINH IN BANG ASCII===\n");
	unsigned char c = (unsigned char)(0);
	while (c<= (unsigned char)MAX_LENGTH)
	{
		PrintNum((int)c);
		PrintString(" - ");
		PrintChar(c);
		PrintString("\t");
		if (c==(unsigned char)(MAX_LENGTH)) 
			break;
		if ((int)c%13==0)
			PrintString("\n");
		c++;
	}

	Halt();
}
