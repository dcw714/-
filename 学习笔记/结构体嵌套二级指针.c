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
	// ������ʦ��ָ����ڴ�
	struct teacher **space = (struct teacher **)malloc(sizeof(struct teacher *) * 3);

	for (int i = 0; i < 3; i++)
	{
		// ������ʦ���ڴ�
		space[i] = (struct teacher *)malloc(sizeof(struct teacher));// ע�⣺�����ڴ��������ڷ���
		// ����ʦ�����ַ����ڴ沢��ֵ
		space[i]->name = (char *)malloc(sizeof(char) * 128);
		sprintf(space[i]->name, "teacher_%d", i + 1);
		// ����ѧ���ǵ��ڴ�
		space[i]->students = (char **)malloc(sizeof(char *) * 4);
		for (int j = 0; j < 4; j++)
		{
			// ��ѧ������ռ䲢��ֵ
			space[i]->students[j] = (char *)malloc(sizeof(char) * 128);
			sprintf(space[i]->students[j], "%s_student_%d", space[i]->name, i + 1);
		}
	}
	*teachers_addr = space;
	return;
}

void printTeacher(struct teacher **teachers, int len)
{
	// ��ӡ
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
	// �ͷ��ڴ� 
	// ע�������ڲ�������ͷ� ����Ҫ��˳��������ֱ�ӱ�
	for (int i = 0; i < len; i++)
	{
		// �ͷ���ʦ����
		if (teachers[i]->name != NULL)
		{
			free(teachers[i]->name);
			teachers[i]->name = NULL;
		}
		// �ͷ�ѧ��
		for (int j = 0; j < 4; j++)
		{
			if (teachers[i]->students[j] != NULL)
			{
				free(teachers[i]->students[j]);
				teachers[i]->students[j] = NULL;
			}
		}
		// �ͷ�ѧ����
		if (teachers[i]->students != NULL)
		{
			free(teachers[i]->students);
			teachers[i]->students = NULL;
		}
		// �ͷ���ʦ
		free(teachers[i]);
		teachers[i] = NULL;

	}
	// �ͷ���ʦ��

	free(teachers);
	teachers = NULL;
	return;
}

void text_struct_secondary_pointer()
{
	// �����ڴ�ռ䣬��ֵ
	struct teacher **teachers = NULL;
	allocateSpaceSecondary(&teachers);
	// ��ӡ
	printTeacher(teachers, 3);
	/*
	�����
	teacher_1
	teacher_1_student_1     teacher_1_student_1     teacher_1_student_1     teacher_1_student_1
	teacher_2
	teacher_2_student_2     teacher_2_student_2     teacher_2_student_2     teacher_2_student_2
	teacher_3
	teacher_3_student_3     teacher_3_student_3     teacher_3_student_3     teacher_3_student_3
	*/
	// �ͷ��ڴ�
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