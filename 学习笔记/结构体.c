#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ṹ�壺�ܹ��������ͬ��ͬ��������һͬ�������������

// �ṹ�����Ͷ���
struct people
{
	char name[128];
	int age;
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
}XiaoJingTing, ChenPengWei; //����������͵Ľṹ�����XiaoJingTing��ChenPengWei�˷���ֻ�����ⶨ��

*/
/*
�ṹ�����ͺͽṹ�������ϵ��
�ṹ�����ͣ�ָ����һ���ṹ�����ͣ����൱��һ��ģ�ͣ������в��޾������ݣ�ϵͳ��֮Ҳ������ʵ���ڴ浥Ԫ��
�ṹ�������ϵͳ���ݽṹ�����ͣ��ڲ���Ա״����Ϊ֮����ռ䡣
*/

void text(struct people yangYang);
void text2(struct people *yangYang);
void setSwordman(struct people *swordsman);

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
		firstGenerationKuiBa.basicInfo.name,
		firstGenerationKuiBa.basicInfo.age,
		firstGenerationKuiBa.skill);

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
	setSwordman(swordsman, sizeof(swordsman) / sizeof(swordsman[0]));
	for (int i = 0; i < sizeof(swordsman) / sizeof(swordsman[0]); i++)
	{
		printf("����%s,����%d�ꡣ\n", swordsman[i].name, swordsman[i].age);
	}
	return 0;
}

void text(struct people yangYang)
{
	yangYang.age = 18;
}

void text2(struct people *yangYang)
{
	yangYang->age = 18;
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
}