#pragma once
#include "Data.h"
#include "pgh.h"
const char* print_city(int N) {
	const char* value;
	if (N < 0) {
		value = "미설정";
		return value;
	}
	else {
		value = city_number[N];
		return value;
	}
}
int research(char* s) {
	int n;
	int list[Max_JC];
	int select=0;
	while (1) {
		n = 0;
		printf("검색어 : %s  \n-검색 결과\n", s);
		for (int i = 0; i < Max_JC; i++) {
			if (strstr(city_number[i], s) != NULL || strstr(s, city_number[i])!=NULL) {
				printf("%d.%s\n", n, city_number[i]);
				list[n++] = i;
			}
		}
		if (n == 0)
			printf("검색결과가 없습니다\n");
		printf("%d.재검색\n", n++);
		printf("%d.뒤로가기                 : ", n);
		scanf_s("%d", &select);
		printf("\n");
		if (select == n)
			return -1;
		else if (select == n - 1) {
			printf("\n검색어 : ");
			scanf("%s", s);
		}
		else if (select < n - 1 && select >= 0) {
			return list[select];
		}
		else {
			printf("잘못 입력하셨습니다\n");
		}
	}
}