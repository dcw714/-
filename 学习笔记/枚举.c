#include <stdio.h>

/*
ö�٣���������ֵһһ�оٳ�����������ֵֻ�����оٳ�����ֵ�ķ�Χ�ڡ�
��ö��ֵ����Ӧ�г����п���ֵ��Ҳ��Ϊö��Ԫ�ء�
ö��ֵ�ǳ����������ڳ������ø�ֵ����ٶ�����ֵ��
ö��Ԫ�ر�����ϵͳ������һ����ʾ��ŵ���ֵ��0��ʼ˳����Ϊ0��1��2 ��
*/

typedef enum BOOL
{
	false,
	true
}bool;

int main_enum(void)
{
	bool a;
	a = false;
	printf("false: %d, true: %d a: %d", false, true, a);
}