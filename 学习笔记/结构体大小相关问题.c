#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // offsetof ��ͷ�ļ�
// #pragma pack(show)
// Ĭ�ϵĶ���ģ��
//  warning C4810: ��ע pack(show) ��ֵ == 8

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
	// �޽ṹ��Ƕ��ͨ��ƫ��������
	struct num t = { 'a', 99 };
	struct num *p = &t;
	int offsize1 = (int)&(p->b) - (int)p;
	int offsize2 = offsetof(struct num, b); // ���ã����ؽṹ���г�Ա������׵�ַ��ƫ����
	printf("offsize1 = %d; offsize2 = %d\n", offsize1, offsize2);
	// �����offsize1 = 4; offsize2 = 4

	// ͨ��ƫ�������ʳ�Ա����
	printf("b = %d;\n", *(int *)((char *)p + offsize1)); // �����b = 99;


	// �нṹ��Ƕ��ͨ��ƫ��������
	struct numUpgrade t1 = { 'a', 99, 'b', 999 };
	// ���ҵ��ṹ��numGrade�ĵ�ַ������c������׵�ַ��ƫ�������ڼ���c��b������׵�ַ��ƫ����
	printf("Ƕ�׽ṹ��c��a��ֵ��%d", *(int*)((char *)&t1 +
		offsetof(struct numUpgrade, c) +
		offsetof(struct num, b)));
	// �����Ƕ�׽ṹ��c��a��ֵ��999

	// ���ҵ��ṹ��numGrade�ĵ�ַ������c������׵�ַ��ƫ�����õ�c���׵�ַ��ǿתΪstruct num *����
	printf("Ƕ�׽ṹ��c��a��ֵ��%d\n", ((struct num *)((char *)&t1 +
		offsetof(struct numUpgrade, c)))->b);
	// �����Ƕ�׽ṹ��c��a��ֵ��999

	// �ڴ���� �Կռ任ʱ��
	/*
	����sizeof���������ĳ�ṹ����ռ�ռ�ʱ�������Ǽ򵥵ؽ��ṹ��������Ԫ�ظ���ռ�Ŀռ���ӣ�
	�����漰���ڴ��ֽڶ�������⡣
	�������Ͻ��������κα����ķ��ʶ����Դ��κε�ַ��ʼ���ʣ�������ʵ�ϲ�����ˣ�
	ʵ���Ϸ����ض����͵ı���ֻ�����ض��ĵ�ַ���ʣ������Ҫ���������ڿռ��ϰ�һ���Ĺ������У� 
	�����Ǽ򵥵�˳�����У�������ڴ���롣

	�ڴ�����ԭ��
	cpu���ڴ浱�ɶ���飬ÿ�δ��ڴ��ж�ȡһ���飬�����Ĵ�С������2��4��8��16�ȣ�
	
	�ڴ�����ǲ���ϵͳΪ����߷����ڴ�Ĳ��ԡ�����ϵͳ�ڷ����ڴ��ʱ��
	ÿ�ζ�ȡһ������(��������ǲ���ϵͳĬ�ϵĶ�����������Ĭ�϶�������������)��
	���û�ж��룬Ϊ�˷���һ���������ܲ������η��ʡ�

	����ڴ���룺
	���ڱ�׼�������ͣ����ĵ�ַֻҪ�����ĳ��ȵ���������
	���ڷǱ�׼�������ͣ�����ṹ�壬Ҫ��ѭһ�¶���ԭ��
	1.��һ����Ա����offsetΪ0�ĵط�
	2.�Ժ�ÿ�������ԱӦ�÷���offsetΪ  min����ǰ��Ա�Ĵ�С��#pargama pack(n)/ ����ģ�� ���������ĵط���ʼ
	3.�����г�Ա������Ϻ�������ƫ�ƣ� �ṹ���ܵĴ�С��Ҳ����sizeof�Ľ����
	������min���ṹ���ڲ�����Ա��#pargama pack(n)/ / ����ģ������������������Ҫ���롣
	3. �ṹ����Ϊ��Ա�Ķ���������һ���ṹ��B��Ƕ����һ���ṹ��A,����������Ա���͵Ĵ�С���룬
	���ǽṹ��A�����ΪA�ڲ�����Ա���������ĵط���
	��struct B�����struct A��A����char��int��double�ȳ�Ա����AӦ�ô�8����������ʼ�洢������
	�ṹ��A�еĳ�Ա�Ķ������������ԭ��1��ԭ��2��

	�鿴����ģ����?#pragma pack(show)
					��ʾ��ǰpacking alignment���ֽ�������warning message����ʽ����ʾ��
?  �ֶ����ö���ģ����   #pragma pack(n)
                    ָ��packing����ֵ�����ֽ�Ϊ��λ��ȱʡ��ֵ��8���Ϸ�����ֵ�ֱ���1,2,4,8,16��
	*/

	struct textOffset
	{
		char a; // 0-3
		int b; // 4-7
		double c; // 8-15
		int d; // 16-19
	}; // ����struct textOffset�ڲ�����֮��Ĵ�СΪ20 �����������룬
	// ����Ϊ������͵������� Ҳ����8�������� Ϊ24
	printf("%d\n", sizeof(struct textOffset)); // �����24

	struct textOffsetGrade
	{
		char a; // 0-3
		int b; // 4-7
		double c; // 8-15
		struct textOffset d; //�ýṹ�������ĳ�ԱΪ8���ֽڣ����Դ�8�ı�����ʼ����
		/*
		struct textOffset
	{
		char a; // 16 -19
		int b; // 20-23
		double c; // 24-31
		int d; // 32-35
	};����struct textOffsetGrade�ڲ�����֮��Ĵ�СΪ36�����������룬
	  ����Ϊ������͵������� Ҳ����8�������� Ϊ40
		*/
	};
	printf("%d\n", sizeof(struct textOffsetGrade)); // �����40

	system("pause");
	return 0;
}