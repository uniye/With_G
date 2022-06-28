#define _CRT_SECURE_NO_WARNINGS //���� �ذ�

#include <stdio.h>
#include <stdlib.h> //malloc�� ���� ���� �������
#include <string.h> //strcpy �Լ� ����� ���� ��.

typedef struct Week {
	char weekname[100]; //stringŸ���� ���⿡ list ����
	struct Week* nextWeek; //�������
}Week;

/*
struct Week{
	...
	struct Week* nextWeek;
};
typedef struct Week Week; ����
*/

main() {
	//Week* head = malloc(sizeof(struct Week)); => �̷��� ���� head �����ص� �Ǵµ� h�� �����.
	Week* headweek = malloc(sizeof(struct Week));
	//headweek->weekname = "Mon"; 
	//�� �´ٸ´� strŸ���� �׳� ���� ������ ������ 
	//=> strcpy �̿��� ��
	strcpy(headweek->weekname, "Mon");
	headweek->nextWeek = NULL;

	Week* week = (Week*)malloc(sizeof(struct Week));
	strcpy(week->weekname, "Tue");
	week->nextWeek = NULL;

	//���� �̾��ֱ�
	headweek->nextWeek = week;

	/*
	Week* h = headweek; //head�� ������ ����
	
	//����غ���.
	for (; h != NULL; h = h->nextWeek){
		printf("%s\n",h->weekname);
	}
	*/
	

	//��� ���� ������� �Է� �� ��� (���� ����: Sun, Wen, Thur, Fri, Sat)
	char weeks[4][100] = {"Wen","Thur","Fri","Sat"};
	for (int i = 0; i < 4; i++) {
		Week* week1 = (Week*)malloc(sizeof(struct Week));
		strcpy(week1->weekname, weeks[i]);
		week1->nextWeek = NULL;
		week->nextWeek = week1;
		week = week->nextWeek;
	}
	

	Week* week2 = (Week*)malloc(sizeof(struct Week));
	strcpy(week2->weekname, "Sun");
	week2->nextWeek = headweek;
	headweek = week2;

	Week* h1 = headweek; //head�� ������ ����

	//����غ���.
	for (; h1 != NULL; h1 = h1->nextWeek) {
		printf("%s\n", h1->weekname);
	}


}	