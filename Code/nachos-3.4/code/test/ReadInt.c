#include "syscall.h"

int main() {
    int number;
    char c;
    char str[150];
    int len = 150;
    int check_compare = 0;
    int n, m;
    char str_bubble[200];

    PrintString("nhap so nguyen: ");
    number = ReadInt();
    //PrintString("\n");
    PrintString("so nguyen da nhap la: ");
    PrintInt(number);
    PrintString("\n\n");

    PrintString("Nhap 1 ky tu: ");
    c = ReadChar();
    //PrintString("\n");
    PrintString("Ky tu da nhap la: ");
    PrintChar(c);
    PrintString("\n\n");

    PrintString("chuoi can nhap: ");
    ReadString(str, len);
    PrintString("chuoi nhap la: ");
    PrintString(str);
    PrintString("\n\n");
}