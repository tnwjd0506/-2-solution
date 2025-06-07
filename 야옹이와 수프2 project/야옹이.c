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

    printf("**** �߿��̿� ���� ****\n");
    printf("         /\\_/\\   \n");
    printf("   /\\   / o o \\  \n");
    printf("  //\\\\  \\~(*)~/  \n");
    printf("  `   \\/   ^ /   \n");
    printf("      |  \\|| ||  \n");
    printf("      \\  '|| ||  \n");
    printf("       \\) ()-()) \n");
    printf("�߿����� �̸��� �ڿ��Դϴ�.\n");
    Sleep(1000);//1�� ���
    system("cls");
    srand((unsigned int)time(NULL));

    while (1) {
        printf("==================== ���� ���� ===================\n");
        printf("������� ���� ����: %d��\n", soup);
        printf("CP: %d����Ʈ \n", cp);
        printf("�ڿ��� ���(0~3): %d\n", feeling);
        switch (feeling) {
        case 0:
            printf(" ����� �ſ� ���޴ϴ�.\n");
            break;
        case 1:
            printf(" �ɽ����մϴ�.\n");
            break;
        case 2:
            printf(" �Ļ��� �����ϴ�.\n");
            break;
        case 3:
            printf(" ������ �θ��ϴ�.\n");
            break;
        }
        printf("������� ����(0~4): %d\n", relationship);
        switch (relationship) {
        case 0:
            printf(" �翡 ���°����� �Ⱦ��մϴ�.\n");
            break;
        case 1:
            printf(" ���� ���Ǳ� ����Դϴ�.\n");
            break;
        case 2:
            printf(" �׷����� ������ �����Դϴ�.\n");
            break;
        case 3:
            printf(" �Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
            break;
        case 4:
            printf(" ���� ������ �Դϴ�.\n");
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