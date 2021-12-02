// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

// Doi thanh ghi Program counter cua he thong ve sau 4 byte de tiep tuc nap lenh
void IncreasePC()
{
	// trong machine/machine.h -- Ham int ReadRegister(int num) doc thanh ghi thu 'num'
	// bien counter doc dia chi PCReg (hien tai)
	int counter = machine->ReadRegister(PCReg); 

	// viet gia tri nay vao thanh ghi trc do
	// trong machine/machine.h -- Ham void WriteRegister(int num, int value) ghi 'value' vao thanh ghi thu 'num'
	machine->WriteRegister(PrevPCReg, counter); 

	// tiep tuc doc gia tri thanh ghi ke tiep va gan vao thanh ghi hien tai
	counter = machine->ReadRegister(NextPCReg);
	machine->WriteRegister(PCReg, counter);
	
	// viet dia chi cau lenh ke tiep
	machine->WriteRegister(NextPCReg, counter + 4);

	// Thay IncreasePC vao Halt Systemcall
}

// bien which la loai Exception
void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
	int op1, op2, result;
	int size;
	char s[200];
	char* s2;
	int a;

	switch (which)
	{
		case NoException: 
			return;

		case PageFaultException:
		{
			printf("No valid translation found \n");
			interrupt->Halt();
			break;
		}

		case ReadOnlyException:
		{
			printf("\n\n Write attempted to page marked 'read-only' \n");;
			interrupt->Halt();
			break;
		}
		case BusErrorException:
		{
			printf("\n\n Translation resulted invalid physical address. \n");
			interrupt->Halt();
			break;
		}
		case AddressErrorException:
		{
			printf("\n\n Unaligned reference or one that was beyond the end of the address space. \n");
			interrupt->Halt();
			break;
		}
		case OverflowException:
		{
			printf("\n\n Integer overflow in add or sub. \n");
			interrupt->Halt();
			break;
		}
		case IllegalInstrException:
		{
			printf("\n\n Unimplemented or reserved instr. \n");
			interrupt->Halt();
			break;
		}
		case NumExceptionTypes:
		{
			printf("\n\n Number exception types. \n");
			interrupt->Halt();
			break;
		}
		case SycallException:
		{
			switch (type)
			{
				case SC_Halt;
				{
					DEBUG('a', "Shutdown, initiated by user program. \n);
					interrupt->Halt();
					break;
				}
			}
		}
		default:
			printf("Unexpected user mode exception %d %d \n", which, type);
			break;
	}
    
}
