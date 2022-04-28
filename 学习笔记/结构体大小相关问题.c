#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // offsetof 的头文件
// #pragma pack(show)
// 默认的对齐模数
//  warning C4810: 杂注 pack(show) 的值 == 8

struct num
{
	char a;
	int b;
};

struct numUpgrade
{
	char a;
	int b;
	struct num c;
};

// int main(void)
int main_struct_size(void)
{
	// 无结构体嵌套通过偏移量访问
	struct num t = { 'a', 99 };
	struct num *p = &t;
	int offsize1 = (int)&(p->b) - (int)p;
	int offsize2 = offsetof(struct num, b); // 作用：返回结构体中成员相对于首地址的偏移量
	printf("offsize1 = %d; offsize2 = %d\n", offsize1, offsize2);
	// 输出：offsize1 = 4; offsize2 = 4

	// 通过偏移量访问成员内容
	printf("b = %d;\n", *(int *)((char *)p + offsize1)); // 输出：b = 99;


	// 有结构体嵌套通过偏移量访问
	struct numUpgrade t1 = { 'a', 99, 'b', 999 };
	// 先找到结构体numGrade的地址，加上c相对于首地址的偏移量，在加上c中b相对于首地址的偏移量
	printf("嵌套结构体c中a的值：%d", *(int*)((char *)&t1 +
		offsetof(struct numUpgrade, c) +
		offsetof(struct num, b)));
	// 输出：嵌套结构体c中a的值：999

	// 先找到结构体numGrade的地址，加上c相对于首地址的偏移量得到c的首地址，强转为struct num *类型
	printf("嵌套结构体c中a的值：%d\n", ((struct num *)((char *)&t1 +
		offsetof(struct numUpgrade, c)))->b);
	// 输出：嵌套结构体c中a的值：999

	// 内存对齐 以空间换时间
	/*
	在用sizeof运算符求算某结构体所占空间时，并不是简单地将结构体中所有元素各自占的空间相加，
	这里涉及到内存字节对齐的问题。
	从理论上讲，对于任何变量的访问都可以从任何地址开始访问，但是事实上不是如此，
	实际上访问特定类型的变量只能在特定的地址访问，这就需要各个变量在空间上按一定的规则排列， 
	而不是简单地顺序排列，这就是内存对齐。

	内存对齐的原因：
	cpu将内存当成多个块，每次从内存中读取一个块，这个块的大小可能是2、4、8、16等，
	
	内存对齐是操作系统为了提高访问内存的策略。操作系统在访问内存的时候，
	每次读取一定长度(这个长度是操作系统默认的对齐数，或者默认对齐数的整数倍)。
	如果没有对齐，为了访问一个变量可能产生二次访问。

	如何内存对齐：
	对于标准数据类型，它的地址只要是它的长度的整数倍。
	对于非标准数据类型，比如结构体，要遵循一下对齐原则：
	1.第一个成员放在offset为0的地方
	2.以后每个数组成员应该放在offset为  min（当前成员的大小，#pargama pack(n)/ 对齐模数 ）整数倍的地方开始
	3.当所有成员计算完毕后做二次偏移， 结构体总的大小，也就是sizeof的结果，
	必须是min（结构体内部最大成员，#pargama pack(n)/ / 对齐模数）的整数倍，不足要补齐。
	3. 结构体做为成员的对齐规则。如果一个结构体B里嵌套另一个结构体A,还是以最大成员类型的大小对齐，
	但是结构体A的起点为A内部最大成员的整数倍的地方。
	（struct B里存有struct A，A里有char，int，double等成员，那A应该从8的整数倍开始存储。），
	结构体A中的成员的对齐规则仍满足原则1、原则2。

	查看对齐模数：?#pragma pack(show)
					显示当前packing alignment的字节数，以warning message的形式被显示。
?  手动设置对齐模数：   #pragma pack(n)
                    指定packing的数值，以字节为单位，缺省数值是8，合法的数值分别是1,2,4,8,16。
	*/

	struct textOffset
	{
		char a; // 0-3
		int b; // 4-7
		double c; // 8-15
		int d; // 16-19
	}; // 所以struct textOffset内部对齐之后的大小为20 ，最后整体对齐，
	// 整体为最大类型的整数倍 也就是8的整数倍 为24
	printf("%d\n", sizeof(struct textOffset)); // 输出：24

	struct textOffsetGrade
	{
		char a; // 0-3
		int b; // 4-7
		double c; // 8-15
		struct textOffset d; //该结构体中最大的成员为8个字节，所以从8的倍数开始对齐
		/*
		struct textOffset
	{
		char a; // 16 -19
		int b; // 20-23
		double c; // 24-31
		int d; // 32-35
	};所以struct textOffsetGrade内部对齐之后的大小为36，最后整体对齐，
	  整体为最大类型的整数倍 也就是8的整数倍 为40
		*/
	};
	printf("%d\n", sizeof(struct textOffsetGrade)); // 输出：40

	system("pause");
	return 0;
}