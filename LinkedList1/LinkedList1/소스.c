#define _CRT_SECURE_NO_WARNINGS //오류 해결

#include <stdio.h>
#include <stdlib.h> //malloc을 쓰기 위한 헤더파일
#include <string.h> //strcpy 함수 사용을 위한 것.

typedef struct Week {
	char weekname[100]; //string타입이 없기에 list 형태
	struct Week* nextWeek; //다음노드
}Week;

/*
struct Week{
	...
	struct Week* nextWeek;
};
typedef struct Week Week; 가능
*/

int add_after(Week* prev, char* item);
int strcmp_ptr(const char* ptr1, const char* ptr2);

main() {
	//Week* head = malloc(sizeof(struct Week)); => 이렇게 만들어서 head 지정해도 되는데 h로 대신함.
	Week* headweek = malloc(sizeof(struct Week));
	//headweek->weekname = "Mon"; 
	//아 맞다맞다 str타입은 그냥 집어 넣으면 오류남 
	//=> strcpy 이용할 것
	strcpy(headweek->weekname, "Mon");
	headweek->nextWeek = NULL;

	Week* week = (Week*)malloc(sizeof(struct Week));
	strcpy(week->weekname, "Tue");
	week->nextWeek = NULL;

	//둘을 이어주기
	headweek->nextWeek = week;

	/*
	Week* h = headweek; //head의 포인터 지정
	
	//출력해보자.
	for (; h != NULL; h = h->nextWeek){
		printf("%s\n",h->weekname);
	}
	*/
	

	//모든 요일 순서대로 입력 및 출력 (남은 요일: Sun, Wen, Thur, Fri, Sat)
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

	Week* h1 = headweek; //head의 포인터 지정

	//출력해보자.
	for (; h1 != NULL; h1 = h1->nextWeek) {
		printf("%s\n", h1->weekname);
	}
	printf("\n");
	printf("\n");

	
	//만약 Wen 다음에 힘듬이라는 단어를 추가 하고 싶음
	Week* h2 = headweek;
	char* findw = "Wen";
	Week* w = malloc(sizeof(struct Week));
	for (; h2 != NULL; h2 = h2->nextWeek) {
		if (strcmp_ptr(h2->weekname, findw)==1) {
			w = h2;
		}
	}
	
	char *addw = "힘듬";
	add_after(w, addw);
	for (; headweek != NULL; headweek = headweek->nextWeek) {
		printf("%s\n", headweek->weekname);
	}
	

}	
//이를 기반으로 만들어본 함수
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