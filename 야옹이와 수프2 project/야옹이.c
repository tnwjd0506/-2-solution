#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ROOM_WIDTH 10
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH-2)


int main(void) {
    int soup = 0, relationship = 2, cat = 1;
    int cp = 0, feeling = 3, scratcher = 0, tower = 0;
    int foot=0;

    printf("**** 야옹이와 수프 ****\n");
    printf("         /\\_/\\   \n");
    printf("   /\\   / o o \\  \n");
    printf("  //\\\\  \\~(*)~/  \n");
    printf("  `   \\/   ^ /   \n");
    printf("      |  \\|| ||  \n");
    printf("      \\  '|| ||  \n");
    printf("       \\) ()-()) \n");
    printf("야옹이의 이름은 코옹입니다.\n");
    Sleep(1000);//1초 대기
    system("cls");
    srand((unsigned int)time(NULL));

    while (1) {
        printf("==================== 현재 상태 ===================\n");
        printf("현재까지 만든 수프: %d개\n", soup);
        printf("CP: %d포인트 \n", cp);
        printf("코옹의 기분(0~3): %d\n", feeling);
        switch (feeling) {
        case 0:
            printf(" 기분이 매우 나쁩니다.\n");
            break;
        case 1:
            printf(" 심심해합니다.\n");
            break;
        case 2:
            printf(" 식빵을 굽습니다.\n");
            break;
        case 3:
            printf(" 골골송을 부릅니다.\n");
            break;
        }
        printf("집사와의 관계(0~4): %d\n", relationship);
        switch (relationship) {
        case 0:
            printf(" 곁에 오는것조차 싫어합니다.\n");
            break;
        case 1:
            printf(" 간식 자판기 취급입니다.\n");
            break;
        case 2:
            printf(" 그럭저럭 쓸만한 집사입니다.\n");
            break;
        case 3:
            printf(" 훌륭한 집사로 인정받고 있습니다.\n");
            break;
        case 4:
            printf(" 집사 껌딱지 입니다.\n");
            break;
        }
        printf("==================================================\n\n");
        Sleep(500);


        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0 || i == ROOM_WIDTH - 1) {
                printf("#");
            }
            else if (i == 1) {
                printf("H");
            }
            else if (i == BWL_PO) {
                printf("B");
            }
            else if (i == scratcher) {
                printf("S");
            }
            else if (i == tower) {
                printf("T");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0 || i == ROOM_WIDTH - 1) {
                printf("#");
            }
            else if (i == cat) {
                printf("C");
            }
            else if (i == foot) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");
        Sleep(500);
    }
    return 0;
}