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

// �ṹ�壺�ܹ��������ͬ��ͬ��������һͬ�������������

// �ṹ�����Ͷ���
struct people
{
	char name[128];
	int age;
	// void text();�ṹ���в������庯��
	// int heigh = 10; c���Խṹ�岻������ֵ
};
/*
  struct��������һ���ṹ�� people������ṹ������
  struct people������ṹ�������
  ����ṹ������������Ա �ṹ���еĳ�Ա��������������
  ע�⣺�ṹ��������ֻ��һ�����ͣ�һ��ģ�壬û�пռ䣬���ܸ�ֵ
*/
/*

struct people
{
	char name[128];
	int age;
}XiaoJingTing; //����struct people����ṹ�����͵�ͬʱ������struct people������͵Ľṹ�����XiaoJingTing

*/
/*

struct
{
char name[128];
int age;
}XiaoJingTing, ChenPengWei; //�����Ľṹ�����������������͵Ľṹ�����XiaoJingTing��ChenPengWei�˷���ֻ�����ⶨ��

*/
/*
�ṹ�����ͺͽṹ�������ϵ��
�ṹ�����ͣ�ָ����һ���ṹ�����ͣ����൱��һ��ģ�ͣ������в��޾������ݣ�ϵͳ��֮Ҳ������ʵ���ڴ浥Ԫ��
�ṹ�������ϵͳ���ݽṹ�����ͣ��ڲ���Ա״����Ϊ֮����ռ䡣
*/

void text(struct people yangYang);
void text2(struct people *yangYang);
void setSwordman(struct people *swordsman, int count);

int main(void)
{
	// �ṹ������Ķ���
	struct people ChenPengWei;


	// �ṹ������ĳ�ʼ��
	struct people XiaoJingTing = { "Ф��ͤ", 22 };
	struct people WanFang = { .name = "��"}; //����ȫ��ʼ��

	//�ṹ���Ա��ֵֵ(��β����ṹ���Ա)
	//�����ͨ���ṹ�������������ʹ�õ���(.)����
	WanFang.age = 22;


	//�����ͨ���ṹ������ĵ�ַ��������ʹ��(->)����
	(&ChenPengWei)->age = 22;
	// (&ChenPengWei)->name = "ChenPengWei"; err:��������һ������
	strcpy((&ChenPengWei)->name, "�����");
	printf("%s�������ǣ�%d��\n", ChenPengWei.name, (&ChenPengWei)->age);


	// �ṹ�����飺��һ�����飬�����е�ÿһ��Ԫ�ض���һ���ṹ��
	struct people peoples[3] =
	{
		{"�⺣��", 22},
		{"�ƴ���", 23},
		{"����", 24}
	};// ������һ���ṹ�����飬������Ԫ�أ�ÿ��Ԫ�ض���һ���ṹ��
	for(int i = 0; i < 3; i++)
	{
		printf("��Һã�������ϰʱ��%d���ż����ϰ��%s���ҽ���%d�ꡣ\n", i + 1, peoples[i].name, peoples[i].age);
	}


	//�ṹ��Ƕ�׽ṹ��
	struct superman
	{
		// char name[128];
		// int age;
		struct people basicInfo;
		char skill[128];
	};
	struct superman yuHong;
	strcpy(yuHong.basicInfo.name, "���");
	yuHong.basicInfo.age = 22;
	strcpy(yuHong.skill, "����������һ������2000�����");
	printf("����%s����%d�꣬���ļ����ǣ�%s��\n", yuHong.basicInfo.name, yuHong.basicInfo.age, yuHong.skill);


	//�ṹ�帳ֵ
	struct superman firstGenerationKuiBa = { "anonymous", 10000, "�������л���֮����������սʤ������겻���������������ԻḴ�" };
	struct superman secondGenerationKuiBa = firstGenerationKuiBa; //ͬ�����͵ı�������ֱ�Ӹ�ֵ���ڲ���memcpyʵ��
	printf("��һ�����ν�%s�����Ѿ�%d���ˣ����ļ�����%s��\n",
		firstGenerationKuiBa.basicInfo.name, 
		firstGenerationKuiBa.basicInfo.age,
		firstGenerationKuiBa.skill);

	printf("�ڶ������ν�%s�����Ѿ�%d���ˣ����ļ�����%s��\n",
		secondGenerationKuiBa.basicInfo.name,
		secondGenerationKuiBa.basicInfo.age,
		secondGenerationKuiBa.skill);

	//�ṹ����ָ��

	//�ṹ��ָ��
	struct superman manJi = firstGenerationKuiBa;
	strcpy(manJi.basicInfo.name, "����");
	manJi.basicInfo.age = 12;

	// ָ����ͨ�����Ľṹ��ָ��
	struct superman *p;
	// printf("%s�ǵ��������Σ�������%d�꣬���ļ����ǣ�%s", p->basicInfo.name, p->basicInfo.age, p->skill); p��һ��Ұָ��
	p = &manJi;
	printf("%s�ǵ��������Σ�������%d�꣬���ļ����ǣ�%s\n", p->basicInfo.name, p->basicInfo.age, p->skill);

	// ָ������Ľṹ��ָ��
	p = (struct superman *)malloc(sizeof(struct superman));
	strcpy(p->basicInfo.name, "ʷ�ٷ�");
	p->basicInfo.age = 20;
	strcpy(p->skill, "δ֪");
	printf("%s�ǳ��ˣ�������%d�꣬���ļ����ǣ�%s\n", p->basicInfo.name, p->basicInfo.age, p->skill);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	// �ṹ������ָ��
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
	// strcpy(Wei->name, "�˲��");// errĿǰ��һ��Ұָ�룬û�пռ�
	// Wei->name = "�˲��"; ָ�����ֳ��������ԣ��������·�ʽ
	Wei->name = (char *)malloc(128);
	strcpy(Wei->name, "�˲��");
	Wei->age = 18;
	Wei->skill = (struct skills *)malloc(sizeof(struct skills)); //����֮ǰ��ֻ��һ��Ұָ�룬û�г�ʼ��
	Wei->skill->skillName = (char *)malloc(128);
	Wei->skill->skillDescribe = (char *)malloc(128);
	strcpy(Wei->skill->skillName, "��");
	strcpy(Wei->skill->skillDescribe, "��Խһ�У���������");
	printf("���⣬������%s�ܹ�����һ�С�������%d�꣬���ļ�����%s: %s��\n",
		Wei->name,
		Wei->age,
		Wei->skill->skillName,
		Wei->skill->skillDescribe);
	if (Wei->name != NULL)
	{
		free(Wei->name);
		Wei->name = NULL;
	}
	if (Wei->skill->skillDescribe != NULL)//�����������ͷţ���Ȼ������ڴ�й¶
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

	// �ṹ������ָ��ע�������
	struct apple
	{
		char *describe;
		int price;
	};
	
	struct apple apple1;
	struct apple apple2;
	apple1.describe = (char *)malloc(128);
	apple2.describe = (char *)malloc(128);
	strcpy(apple1.describe, "��һ����ƻ����");
	strcpy(apple2.describe, "��һ����ƻ����");
	apple1.price = 5;
	apple2.price = 10;
	printf("��%s���ҵļ۸���%dԪ��\n", apple1.describe, apple1.price);
	printf("��%s���ҵļ۸���%dԪ��\n", apple2.describe, apple2.price);
	/*
	apple1 = apple2;// �˴���ǳ�������ǽ��ڴ��е����ݰ��ֽڿ�����ȥ
	printf("��%s���ҵļ۸���%dԪ��\n", apple1.describe, apple1.price);
	printf("��%s���ҵļ۸���%dԪ��\n", apple2.describe, apple2.price);

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
	�����ڴ��ظ��ͷ� ���ڴ�й¶
	��Ϊ������е���ǳ������apple2�ռ��е����ݰ��ֽڿ�����apple1
	����apple1�е�apple1.describe��apple2�е�apple2.describeָ�����ͬһ����ϵĿռ�
	����apple2.describe�ʼָ��Ŀռ䱻�ڶ����ͷ��� ��apple1.describe�ʼָ��Ŀռ�û���ͷţ��ڴ�й©
	*/
	// ������������apple1.describe�ʼָ��Ŀռ��ͷź��ֶ�����
	if (apple1.describe != NULL)
	{
		free(apple1.describe);
		apple1.describe = NULL;
	}
	apple1.describe = (char *)malloc(128);
	strcpy(apple1.describe, apple2.describe);
	apple1.price = apple2.price;
	printf("��%s���ҵļ۸���%dԪ��\n", apple1.describe, apple1.price);
	printf("��%s���ҵļ۸���%dԪ��\n", apple2.describe, apple2.price);
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
	//�ṹ������������

	// ��ͨ�ṹ���������������
	struct people yangYang = { "����", 22 };
	printf("%s�������ǣ�%d��", yangYang.name, (&yangYang)->age);
	text(yangYang);// �޷����ģ���Ϊ��ֻ��ֵ���ݡ�
	printf("%s�������ǣ�%d��\n", yangYang.name, (&yangYang)->age);

	//�ṹ��ָ���������������
	text2(&yangYang);
	printf("%s�������ǣ�%d��\n", yangYang.name, (&yangYang)->age);

	//�ṹ������������������
	struct people swordsman[3] = { 0 };
	setSwordman(swordsman, (sizeof(swordsman) / sizeof(swordsman[0])));
	for (int i = 0; i < sizeof(swordsman) / sizeof(swordsman[0]); i++)
	{
		printf("����%s,����%d�ꡣ\n", swordsman[i].name, swordsman[i].age);
	}
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
		sprintf(tep, "У԰��%d���͡�", i + 1);
		strcpy((swordsman + i)->name, tep);
		(swordsman + i)->age = i + 17;
	}
	return;
}