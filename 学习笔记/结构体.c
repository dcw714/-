#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h> 

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW
#endif
#endif 

// 结构体：能够将多个相同或不同数据类型一同储存的数据类型

// 结构体类型定义
struct people
{
	char name[128];
	int age;
	// void text();结构体中不允许定义函数
	// int heigh = 10; c语言结构体不允许赋初值
};
/*
  struct代表这是一个结构体 people是这个结构的名字
  struct people是这个结构体的类型
  这个结构体中有两个成员 结构体中的成员可以是任意类型
  注意：结构体类型它只是一个类型，一个模板，没有空间，不能赋值
*/
/*

struct people
{
	char name[128];
	int age;
}XiaoJingTing; //定义struct people这个结构体类型的同时定义了struct people这个类型的结构体变量XiaoJingTing

*/
/*

struct
{
char name[128];
int age;
}XiaoJingTing, ChenPengWei; //匿名的结构体变量，定义这个类型的结构体变量XiaoJingTing和ChenPengWei此方法只能在这定义

*/
/*
结构体类型和结构体变量关系：
结构体类型：指定了一个结构体类型，它相当于一个模型，但其中并无具体数据，系统对之也不分配实际内存单元。
结构体变量：系统根据结构体类型（内部成员状况）为之分配空间。
*/

void text(struct people yangYang);
void text2(struct people *yangYang);
void setSwordman(struct people *swordsman, int count);

int main_struct(void)
// int main(void)
{
	// 结构体变量的定义
	struct people ChenPengWei;


	// 结构体变量的初始化
	struct people XiaoJingTing = { "肖金亭", 22 };
	struct people WanFang = { .name = "万方"}; //不完全初始化

	//结构体成员赋值值(如何操作结构体成员)
	//如果是通过结构体变量操作，则使用点域(.)操作
	WanFang.age = 22;


	//如果是通过结构体变量的地址操作，则使用(->)操作
	(&ChenPengWei)->age = 22;
	// (&ChenPengWei)->name = "ChenPengWei"; err:数组名是一个常量
	strcpy((&ChenPengWei)->name, "陈彭炜");
	printf("%s的年龄是：%d。\n", ChenPengWei.name, (&ChenPengWei)->age);
	// 输出：陈彭炜的年龄是：22。


	// 结构体数组：是一个数组，数组中的每一个元素都是一个结构体
	struct people peoples[3] =
	{
		{"吴海飞", 22},
		{"唐春海", 23},
		{"王俊", 24}
	};// 定义了一个结构体数组，有三个元素，每个元素都是一个结构体
	for(int i = 0; i < 3; i++)
	{
		printf("大家好，我是练习时长%d年的偶像练习生%s，我今年%d岁。\n", i + 1, peoples[i].name, peoples[i].age);
	}
/*
输出：大家好，我是练习时长1年的偶像练习生吴海飞，我今年22岁。
大家好，我是练习时长2年的偶像练习生唐春海，我今年23岁。
大家好，我是练习时长3年的偶像练习生王俊，我今年24岁。
*/


	//结构体嵌套结构体
	struct superman
	{
		// char name[128];
		// int age;
		struct people basicInfo;
		char skill[128];
	};
	struct superman yuHong;
	strcpy(yuHong.basicInfo.name, "余鸿");
	yuHong.basicInfo.age = 22;
	strcpy(yuHong.skill, "初级耐力（一口气跑2000公里）");
	printf("超人%s今年%d岁，他的技能是：%s。\n", yuHong.basicInfo.name, yuHong.basicInfo.age, yuHong.skill);
	// 输出：超人余鸿今年22岁，他的技能是：初级耐力（一口气跑2000公里）。


	//结构体赋值
	struct superman firstGenerationKuiBa = { "anonymous", 10000, "对世界有毁灭之能力，难以战胜。其灵魂不死不灭，肉身死后仍会复活" };
	struct superman secondGenerationKuiBa = firstGenerationKuiBa; //同种类型的变量可以直接赋值，内部是memcpy实现
	printf("第一代魁拔叫%s，他已经%d岁了，他的技能是%s。\n",
		firstGenerationKuiBa.basicInfo.name, 
		firstGenerationKuiBa.basicInfo.age,
		firstGenerationKuiBa.skill);
	// 输出：第一代魁拔叫anonymous，他已经10000岁了，他的技能是对世界有毁灭之能力，难以战胜。其灵魂不死不灭，肉身死后仍会复活。。

	printf("第二代魁拔叫%s，他已经%d岁了，他的技能是%s。\n",
		secondGenerationKuiBa.basicInfo.name,
		secondGenerationKuiBa.basicInfo.age,
		secondGenerationKuiBa.skill);
	// 输出第一代魁拔叫anonymous，他已经10000岁了，他的技能是对世界有毁灭之能力，难以战胜。其灵魂不死不灭，肉身死后仍会复活。。

	//结构体与指针

	//结构体指针
	struct superman manJi = firstGenerationKuiBa;
	strcpy(manJi.basicInfo.name, "蛮吉");
	manJi.basicInfo.age = 12;

	// 指向普通变量的结构体指针
	struct superman *p;
	// printf("%s是第六代魁拔，他今年%d岁，他的技能是：%s。", p->basicInfo.name, p->basicInfo.age, p->skill); p是一个野指针
	p = &manJi;
	printf("%s是第六代魁拔，他今年%d岁，他的技能是：%s\n", p->basicInfo.name, p->basicInfo.age, p->skill);
	// 输出：蛮吉是第六代魁拔，他今年12岁，他的技能是：对世界有毁灭之能力，难以战胜。其灵魂不死不灭，肉身死后仍会复活。

	// 指向堆区的结构体指针
	p = (struct superman *)malloc(sizeof(struct superman));
	strcpy(p->basicInfo.name, "史蒂夫");
	p->basicInfo.age = 20;
	strcpy(p->skill, "未知");
	printf("%s是超人，他今年%d岁，他的技能是：%s\n", p->basicInfo.name, p->basicInfo.age, p->skill);
	// 输出：史蒂夫是超人，他今年20岁，他的技能是：未知

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	// 结构体中套指针
	struct skills
	{
		char *skillName;
		char *skillDescribe;
	};

	struct creator
	{
		char *name;
		int age;
		struct skills *skill;
	};
	struct creator *Wei = (struct creator *)malloc(sizeof(struct creator));
	// strcpy(Wei->name, "邓昌炜");// err目前是一个野指针，没有空间
	// Wei->name = "邓昌炜"; 指向文字常量，可以，或者以下方式
	Wei->name = (char *)malloc(128);
	strcpy(Wei->name, "邓昌炜");
	Wei->age = 18;
	Wei->skill = (struct skills *)malloc(sizeof(struct skills)); //在这之前它只是一个野指针，没有初始化
	Wei->skill->skillName = (char *)malloc(128);
	Wei->skill->skillDescribe = (char *)malloc(128);
	strcpy(Wei->skill->skillName, "零");
	strcpy(Wei->skill->skillDescribe, "超越一切，无所不能");
	printf("在这，创世神%s能够主宰一切。他今年%d岁，他的技能是%s: %s。\n",
		Wei->name,
		Wei->age,
		Wei->skill->skillName,
		Wei->skill->skillDescribe);
	// 输出：在这，创世神邓昌炜能够主宰一切。他今年18岁，他的技能是零: 超越一切，无所不能。
	if (Wei->name != NULL)
	{
		free(Wei->name);
		Wei->name = NULL;
	}
	if (Wei->skill->skillDescribe != NULL)//由里层向外层释放，不然会造成内存泄露
	{
		free(Wei->skill->skillDescribe);
		Wei->skill->skillDescribe = NULL;
	}
	if (Wei->skill->skillName != NULL)
	{
		free(Wei->skill->skillName);
		Wei->skill->skillName = NULL;
	}
	if (Wei->skill != NULL)
	{
		free(Wei->skill);
		Wei->skill = NULL;
	}
	if (Wei != NULL)
	{
		free(Wei);
		Wei = NULL;
	}

	// 结构体中套指针注意的问题
	struct apple
	{
		char *describe;
		int price;
	};
	
	struct apple apple1;
	struct apple apple2;
	apple1.describe = (char *)malloc(128);
	apple2.describe = (char *)malloc(128);
	strcpy(apple1.describe, "是一个酸苹果。");
	strcpy(apple2.describe, "是一个甜苹果。");
	apple1.price = 5;
	apple2.price = 10;
	printf("我%s，我的价格是%d元。\n", apple1.describe, apple1.price);
	printf("我%s，我的价格是%d元。\n", apple2.describe, apple2.price);
	// 输出：我是一个酸苹果。，我的价格是5元。
    //       我是一个甜苹果。，我的价格是10元。
	/*
	apple1 = apple2;// 此处是浅拷贝，是将内存中的内容按字节拷贝过去
	printf("我%s，我的价格是%d元。\n", apple1.describe, apple1.price);
	printf("我%s，我的价格是%d元。\n", apple2.describe, apple2.price);

	if (apple1.describe != NULL)
	{
		free(apple1.describe);
		apple1.describe = NULL;
	}
	if (apple2.describe != NULL)
	{
		free(apple2.describe);
		apple2.describe = NULL;
	}
	错误，内存重复释放 且内存泄露
	因为上面进行的是浅拷贝将apple2空间中的内容按字节拷贝到apple1
	所以apple1中的apple1.describe和apple2中的apple2.describe指向的是同一块堆上的空间
	所以apple2.describe最开始指向的空间被第二次释放了 而apple1.describe最开始指向的空间没被释放，内存泄漏
	*/
	// 改正方法：将apple1.describe最开始指向的空间释放后手动拷贝
	if (apple1.describe != NULL)
	{
		free(apple1.describe);
		apple1.describe = NULL;
	}
	// apple1.describe = (char *)malloc(strlen(apple2.describe));
	apple1.describe = (char *)malloc(strlen(apple2.describe) + 1);
	strcpy(apple1.describe, apple2.describe);
	apple1.price = apple2.price;
	printf("我%s，我的价格是%d元。\n", apple1.describe, apple1.price);
	printf("我%s，我的价格是%d元。\n", apple2.describe, apple2.price);
	// 输出：我是一个甜苹果。，我的价格是10元。
	//       我是一个甜苹果。，我的价格是10元。

	if (apple1.describe != NULL)
	{
		free(apple1.describe);
		apple1.describe = NULL;
	}

	if (apple2.describe != NULL)
	{
		free(apple2.describe);
		apple2.describe = NULL;
	}
	//结构体做函数参数

	// 普通结构体变量做函数参数
	struct people yangYang = { "杨洋", 22 };
	printf("%s的年龄是：%d。", yangYang.name, (&yangYang)->age);
	text(yangYang);// 无法更改，因为这只是值传递。
	printf("%s的年龄是：%d。\n", yangYang.name, (&yangYang)->age);
	// 输出：杨洋的年龄是：22。杨洋的年龄是：22。

	//结构体指针变量做函数参数
	text2(&yangYang);
	printf("%s的年龄是：%d。\n", yangYang.name, (&yangYang)->age);
	// 输出：杨洋的年龄是：18。

	//结构体数组名做函数参数
	struct people swordsman[3] = { 0 };
	setSwordman(swordsman, (sizeof(swordsman) / sizeof(swordsman[0])));
	for (int i = 0; i < sizeof(swordsman) / sizeof(swordsman[0]); i++)
	{
		printf("在下%s,今年%d岁。\n", swordsman[i].name, swordsman[i].age);
	}
	//输出：
	//在下校园第1贱客。, 今年17岁。
	//在下校园第2贱客。, 今年18岁。
	//在下校园第3贱客。, 今年19岁。
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

void text(struct people yangYang)
{
	yangYang.age = 18;
	return;
}

void text2(struct people *yangYang)
{
	yangYang->age = 18;
	return;
}

//void setSwordman(struct people swordsman[])
void setSwordman(struct people *swordsman, int count)
{
	char tep[128] = { 0 };

	for (int i = 0; i < count; i++)
	{
		sprintf(tep, "校园第%d贱客。", i + 1);
		strcpy((swordsman + i)->name, tep);
		(swordsman + i)->age = i + 17;
	}
	return;
}