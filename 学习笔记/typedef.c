#include <stdio.h>
#include <stdlib.h>

/*
	typedef��ΪC���ԵĹؼ��֣�������Ϊһ����������(�������ͻ��Զ�����������)����һ�������֣����ܴ��������͡�
*/

typedef int INT; // ��intȡ����
typedef char CHAR; // ��charȡ����

typedef struct person
{
	char name[128];
	int age;
}PEOPLE;// ���ṹ��ȡ����

int main_typedef(void)
// int main(void)
{
	INT a = 10;
	CHAR b = 20;
	printf("a�Ĵ�СΪ��%d���ֽڡ�b�Ĵ�СΪ��%d���ֽڡ�\n", sizeof(a), sizeof(b));
	PEOPLE people = { "gugu", 18 };
	printf("%s�������ǣ�%d\n", people.name, people.age);
	system("pause");
	return 0;
}