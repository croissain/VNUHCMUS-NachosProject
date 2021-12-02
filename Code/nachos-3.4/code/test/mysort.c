#include "syscall.h"

int A[100];

int main()
{
	int i, j, tmp, choice, n;
	PrintString("===CHUONG TRINH SORT===\n");
	PrintString("Nhap so nguyen n - so phan tu cua mang (<= 100 ): ");
	n=ReadNum();

	if (n>100)
	{
		PrintString("n phai nho hon hoac bang 100\n");
		Halt();
	}

	if (n<1)
	{
		PrintString("n phai la so duong va nho hon hoac bang 100\n");
		Halt();
	}

	for (i=0;i<n;i++)
	{
		PrintString("Nhap A[");
		PrintNum(i);
		PrintString("] = ");
		A[i]=ReadNum();
	}

	PrintString("\nSap xep mang theo thu tu tang dan (nhap 1) / giam dan (nhap 0):  ");
	choice=ReadNum();

	if (choice==1){
		for (i=0;i<n-1;i++){
			for(j=0;j<n-i-1;j++){
				if (A[j] > A[j+1]){
					tmp=A[j];
					A[j]=A[j+1];
					A[j+1]=tmp;
				}
			}
		}
	}
	else{
		for (i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if (A[i] < A[j]){
					tmp=A[j];
					A[j]=A[i];
					A[i]=tmp;
				}
			}
		}

	}
	
	PrintString("\nMang sau khi sap xep: \n ");
	for (i=0;i<n;i++){
		PrintNum(A[i]);
		PrintString("  ");
	}	
	PrintString("\n");
	Halt();
}

