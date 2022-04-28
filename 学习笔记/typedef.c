#include <stdio.h>
#include <stdlib.h>

/*
	typedef：为C语言的关键字，作用是为一种数据类型(基本类型或自定义数据类型)定义一个新名字，不能创建新类型。
*/

typedef int INT; // 给int取别名
typedef char CHAR; // 给char取别名

typedef struct person
{
	char name[128];
	int age;
}PEOPLE;// 给结构体取别名

int main_typedef(void)
// int main(void)
{
	INT a = 10;
	CHAR b = 20;
	printf("a的大小为：%d个字节。b的大小为：%d个字节。\n", sizeof(a), sizeof(b));
	PEOPLE people = { "gugu", 18 };
	printf("%s的年龄是：%d\n", people.name, people.age);
	system("pause");
	return 0;
}