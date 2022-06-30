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

int add_after(Week* prev, char* item);
int strcmp_ptr(const char* ptr1, const char* ptr2);

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
	printf("\n");
	printf("\n");

	
	//���� Wen ������ �����̶�� �ܾ �߰� �ϰ� ����
	Week* h2 = headweek;
	char* findw = "Wen";
	Week* w = malloc(sizeof(struct Week));
	for (; h2 != NULL; h2 = h2->nextWeek) {
		if (strcmp_ptr(h2->weekname, findw)==1) {
			w = h2;
		}
	}
	
	char *addw = "����";
	add_after(w, addw);
	for (; headweek != NULL; headweek = headweek->nextWeek) {
		printf("%s\n", headweek->weekname);
	}
	

}	
//�̸� ������� ���� �Լ�
int add_after(Week* prevweek, char* addw) {
	if (&prevweek == NULL)
		return 0;
	Week* newweek = malloc(sizeof(struct Week));
	strcpy(newweek->weekname, addw);
	newweek->nextWeek = prevweek->nextWeek;
	prevweek->nextWeek = newweek;
	return 1;
}

int strcmp_ptr(const char* ptr1, const char* ptr2) {
	for (int i = 0; ptr1[i] != '\0' || ptr2[i] != '\0'; ++i) {
		if (ptr1[i] != ptr2[i])
			return 0;
	}
	return 1;
}