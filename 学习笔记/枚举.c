#include <stdio.h>

/*
枚举：将变量的值一一列举出来，变量的值只限于列举出来的值的范围内。
在枚举值表中应列出所有可用值，也称为枚举元素。
枚举值是常量，不能在程序中用赋值语句再对它赋值。
枚举元素本身由系统定义了一个表示序号的数值从0开始顺序定义为0，1，2 …
*/

typedef enum BOOL
{
	false,
	true
}bool;

int main_enum(void)
// int main(void)
{
	bool a;
	a = false;
	printf("false: %d, true: %d a: %d", false, true, a);
	return 0;
}