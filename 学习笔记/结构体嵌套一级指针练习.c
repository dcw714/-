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

struct game
{
	char *name;
	int price;
};

struct game **allocateSpace()
{
	// 分配内存
	struct game **games = (struct game **)malloc(sizeof(struct game*) * 3);
	for (int i = 0; i < 3; i++)
	{
		games[i] = (struct game*)malloc(sizeof(struct game));
		games[i]->name = (char *)malloc(sizeof(char) * 64);
		// 赋值
		sprintf(games[i]->name, "星际争霸%d", i + 1);
		games[i]->price = i + 17;
	}
	return games;
}

void printGame(struct game **games, int len)
{
	// 打印
	for (int i = 0; i < len; i++)
	{
		printf("%s的价格是%d$。\n", games[i]->name, games[i]->price);
	}
	return;
}

void freeSpace(struct game **games, int len)
{
	// 释放内存
	if (games == NULL || len <= 0) return;
	for (int i = 0; i < len; i++)// 由内层向外层释放，不然会造成内存泄露
	{
		if (games[i]->name != NULL)
		{
			free(games[i]->name);
			games[i]->name = NULL;
		}
		if (games[i] != NULL)
		{
			free(games[i]);
			games[i] = NULL;
		}
	}
	free(games);
	games = NULL;
}

void text_struct()
{
	struct game **games = NULL; // (struct game **)malloc(sizeof(struct game*));
	games = allocateSpace();//直接利用返回值接收，不然函数内需要三级指针接收
	printGame(games, 3);
	/*
	结果：
	星际争霸1的价格是17$。
	星际争霸2的价格是18$。
	星际争霸3的价格是19$。
	*/
	freeSpace(games, 3);
	games = NULL; // 指向的空间已经被释放，但是它仍然指向那块内存
	return;
}

int main_struct_primary_pointer(void)
// int main(void)
{
	text_struct();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}