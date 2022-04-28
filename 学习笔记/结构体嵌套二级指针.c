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

struct teacher
{
	char *name;
	char **students;
};

void allocateSpaceSecondary(struct teacher ***teachers_addr)
{
	// 分配老师们指针的内存
	struct teacher **space = (struct teacher **)malloc(sizeof(struct teacher *) * 3);

	for (int i = 0; i < 3; i++)
	{
		// 分配老师的内存
		space[i] = (struct teacher *)malloc(sizeof(struct teacher));// 注意：分配内存由外向内分配
		// 给老师的名字分配内存并赋值
		space[i]->name = (char *)malloc(sizeof(char) * 128);
		sprintf(space[i]->name, "teacher_%d", i + 1);
		// 分配学生们的内存
		space[i]->students = (char **)malloc(sizeof(char *) * 4);
		for (int j = 0; j < 4; j++)
		{
			// 给学生分配空间并赋值
			space[i]->students[j] = (char *)malloc(sizeof(char) * 128);
			sprintf(space[i]->students[j], "%s_student_%d", space[i]->name, i + 1);
		}
	}
	*teachers_addr = space;
	return;
}

void printTeacher(struct teacher **teachers, int len)
{
	// 打印
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", teachers[i]->name);

		for (int j = 0; j < 4; j++)
		{
			printf("	%s ", teachers[i]->students[j]);
		}
		printf("\n");
	}
	return;

}

void freeSpaceSecondary(struct teacher **teachers, int len)
{
	if (teachers == NULL || len <= 0) return;
	// 释放内存 
	// 注：需由内层向外层释放 很重要，顺序错误可能直接崩
	for (int i = 0; i < len; i++)
	{
		// 释放老师名字
		if (teachers[i]->name != NULL)
		{
			free(teachers[i]->name);
			teachers[i]->name = NULL;
		}
		// 释放学生
		for (int j = 0; j < 4; j++)
		{
			if (teachers[i]->students[j] != NULL)
			{
				free(teachers[i]->students[j]);
				teachers[i]->students[j] = NULL;
			}
		}
		// 释放学生们
		if (teachers[i]->students != NULL)
		{
			free(teachers[i]->students);
			teachers[i]->students = NULL;
		}
		// 释放老师
		free(teachers[i]);
		teachers[i] = NULL;

	}
	// 释放老师们

	free(teachers);
	teachers = NULL;
	return;
}

void text_struct_secondary_pointer()
{
	// 分配内存空间，赋值
	struct teacher **teachers = NULL;
	allocateSpaceSecondary(&teachers);
	// 打印
	printTeacher(teachers, 3);
	/*
	结果：
	teacher_1
	teacher_1_student_1     teacher_1_student_1     teacher_1_student_1     teacher_1_student_1
	teacher_2
	teacher_2_student_2     teacher_2_student_2     teacher_2_student_2     teacher_2_student_2
	teacher_3
	teacher_3_student_3     teacher_3_student_3     teacher_3_student_3     teacher_3_student_3
	*/
	// 释放内存
	freeSpaceSecondary(teachers, 3);
	return;
}

int main_struct_secondary_pointer(void)
// int main(void)
{
	text_struct_secondary_pointer();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}