#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int  check_sys()
{
	int a = 1;
	return *(char*)&a;
}
int main()
{
	if (1 == check_sys())
		printf("Ð¡¶Ë");
	else
		printf("´ó¶Ë");
	return 0;
}