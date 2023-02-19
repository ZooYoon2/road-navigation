#include "pgh.h"
#include "Dijstra.h"
#include "menu.h"

int main() {
	int play=0;
	int start=-1, end=-1;
	char search[30];
	while (play!=4) {
		printf("==========================================================\n");
		printf("네비게이션 1.출발지 설정 2.도착지 설정 3.경로 검색 4.종료\n");
		printf("출발지 : %s -> 도착지 : %s              메뉴 : ", print_city(start), print_city(end));
		scanf_s("%d", &play);
		if (play == 1) {
			printf("\n출발지 검색 : ");
			scanf("%s", search);
			start = research(search);
		}
		else if (play == 2) {
			printf("\n도착지 검색 : ");
			scanf("%s", search);
			end = research(search);
		}
		else if (play == 3) {
			if (start < 0 || end < 0) {
				printf("출발지 혹은 도착지가 설정되있지 않습니다.\n\n");
			}
			else {
				JC A = Dijstra(start, end);
				printf("\n경로 : ");
				for (int i = 0; i < A.stopover; i++) {
					printf("%s -> ", city_number[A.path[i]]);
				}
				printf("%s\n\n", city_number[A.number]);
				printf("총 거리 : %d Km, 예상 소요 시간 : 약 %d시간 %d분\n\n", A.distance, A.time/60,A.time%60);
			}
		}
		else if (play == 4) { return 0; }
		else {
			printf("없는 메뉴입니다.\n");
		}
	}	
}