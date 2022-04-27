#include <stdio.h>
#include <stdlib.h>

/*
联合体union是一个能在同一个存储空间存储不同类型数据的类型；
联合体所占的内存长度等于其最长成员的长度倍数，也有叫做共用体；
同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用；
共用体变量中起作用的成员是最后一次存放的成员，在存入一个新的成员后原有的成员的值会被覆盖；
  共用体变量的地址和它的各成员的地址都是同一地址
*/

union num
{
	char a;
	int  b;
	short c;
};// 定义和访问方式与结构体类似

int main_union(void)
{
	union num tmp;
	//1、所有成员的首地址是一样的
	printf("%p, %p, %p\n", &(tmp.a), &(tmp.b), &(tmp.c));

	//2、共用体大小为最大成员类型的大小
	printf("%lu\n", sizeof(union num));

	//3、一个成员赋值，会影响另外的成员
	//左边是高位，右边是低位
	//低位放低地址，高位放高地址
	tmp.b = 0x44332211;

	printf("%x\n", tmp.a); //11
	printf("%x\n", tmp.b); //44332211
	printf("%x\n", tmp.c); //2211
	system("pause");
	return 0;
}