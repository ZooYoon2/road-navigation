#pragma once
#include "Data.h"
#include "pgh.h"
const char* print_city(int N) {
	const char* value;
	if (N < 0) {
		value = "�̼���";
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
		printf("�˻��� : %s  \n-�˻� ���\n", s);
		for (int i = 0; i < Max_JC; i++) {
			if (strstr(city_number[i], s) != NULL || strstr(s, city_number[i])!=NULL) {
				printf("%d.%s\n", n, city_number[i]);
				list[n++] = i;
			}
		}
		if (n == 0)
			printf("�˻������ �����ϴ�\n");
		printf("%d.��˻�\n", n++);
		printf("%d.�ڷΰ���                 : ", n);
		scanf_s("%d", &select);
		printf("\n");
		if (select == n)
			return -1;
		else if (select == n - 1) {
			printf("\n�˻��� : ");
			scanf("%s", s);
		}
		else if (select < n - 1 && select >= 0) {
			return list[select];
		}
		else {
			printf("�߸� �Է��ϼ̽��ϴ�\n");
		}
	}
}