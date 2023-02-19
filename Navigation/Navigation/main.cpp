#include "pgh.h"
#include "Dijstra.h"
#include "menu.h"

int main() {
	int play=0;
	int start=-1, end=-1;
	char search[30];
	while (play!=4) {
		printf("==========================================================\n");
		printf("�׺���̼� 1.����� ���� 2.������ ���� 3.��� �˻� 4.����\n");
		printf("����� : %s -> ������ : %s              �޴� : ", print_city(start), print_city(end));
		scanf_s("%d", &play);
		if (play == 1) {
			printf("\n����� �˻� : ");
			scanf("%s", search);
			start = research(search);
		}
		else if (play == 2) {
			printf("\n������ �˻� : ");
			scanf("%s", search);
			end = research(search);
		}
		else if (play == 3) {
			if (start < 0 || end < 0) {
				printf("����� Ȥ�� �������� ���������� �ʽ��ϴ�.\n\n");
			}
			else {
				JC A = Dijstra(start, end);
				printf("\n��� : ");
				for (int i = 0; i < A.stopover; i++) {
					printf("%s -> ", city_number[A.path[i]]);
				}
				printf("%s\n\n", city_number[A.number]);
				printf("�� �Ÿ� : %d Km, ���� �ҿ� �ð� : �� %d�ð� %d��\n\n", A.distance, A.time/60,A.time%60);
			}
		}
		else if (play == 4) { return 0; }
		else {
			printf("���� �޴��Դϴ�.\n");
		}
	}	
}