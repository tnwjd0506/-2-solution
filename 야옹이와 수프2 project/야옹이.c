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
    int dice,up,down,mouse=0,lazer=0,toy=1,a;

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

        printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", relationship, 6 - relationship);
        printf("주사위를 굴립니다. 또르르...\n");

        dice = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다.\n", dice);

        if (dice <= 6 - relationship) {
            printf("코옹의 기분이 나빠집니다: ");
            if (feeling > 0) {
                feeling--;
                printf("%d->%d \n", feeling + 1, feeling);
            }
            else
                printf("0->0 \n");
        }
        else
            printf("기분이 그대로 입니다.\n");


        foot = cat;

        switch (feeling) {
        case 0:
            printf("기분이 매우나쁜 코옹은 집으로향합니다.\n");
            cat--;
            break;
        case 1:
            printf("코옹은 심심해서 스크래처쪽으로 이동합니다.\n");
            if (scratcher != 0 && tower != 0) {
                if (cat != scratcher && cat != tower) {
                    if (cat - scratcher > 0 && cat - tower > 0)
                        cat--;
                    else if (cat - scratcher < 0 && cat - tower < 0)
                        cat++;
                    else {
                        if (tower > scratcher) {
                            up = tower;
                            down = scratcher;
                        }
                        else {
                            up = scratcher;
                            down = tower;
                        }

                        up = up - cat;
                        down = cat - down;

                        if (up > down)
                            cat++;
                        else if (down > up)
                            cat--;
                        else
                            cat++;
                    }
                }

            }
            else if (tower != 0) {
                if (cat > tower)
                    cat--;
                else if (cat < tower)
                    cat++;
                printf("코옹은 심심해서 타워쪽으로 이동합니다.\n");
            }
            else if (scratcher != 0) {
                if (cat > scratcher)
                    cat--;
                else if (cat < scratcher)
                    cat++;
                printf("코옹은 심심해서 스크래처쪽으로 이동합니다.\n");
            }
            else {
                printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
                if (feeling > 0)
                    feeling--;
            }
            break;
        case 2:
            printf("코옹은 기분좋게 식빵을 굽고있습니다.\n");
            break;
        case 3:
            printf("코옹은 골골송을 부르며 수프를 만들러갑니다.\n");
            cat++;
            break;
        }

        if (cat == HME_POS && cat == foot) {
            printf("코옹은 자신의 집에서 편안함을 느낍니다.\n");
            if (feeling < 3)
                feeling++;
        }
        if (cat == BWL_PO) {
            soup++;
            dice = rand() % 3 + 1;
            switch (dice) {
            case 1:
                printf("코옹이 감자수프를 만들었습니다.\n");
                break;
            case 2:
                printf("코옹이 양송이수프를 만들었습니다.\n");
                break;
            case 3:
                printf("코옹이 브로콜리수프를 만들었습니다.\n");
                break;
            }
            printf("현재까지 만든 스푸: %d\n", soup);
        }

        if (cat == scratcher) {
            printf("코옹은 스크래처를 긁고 놀았습니다.\n");
            if (feeling == 3)
                printf("기분이 조금 좋아졌습니다: %d->%d\n", feeling, feeling);
            else {
                feeling++;
                printf("기분이 조금 좋아졌습니다: %d->%d\n", feeling - 1, feeling);
            }
        }

        if (cat == tower) {
            printf("코옹은 캣타워를 뛰어다닙니다.\n");
            if (feeling > 1) {
                printf("기분이 제법 좋아졌습니다: %d->3\n", feeling);
                feeling = 3;
            }
            else {
                feeling += 2;
                printf("기분이 제법 좋아졌습니다: %d->%d\n", feeling - 2, feeling);
            }
        }

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

        printf("어떤 상호작용을 하시겠습니까?\n   0. 아무것도 하지 않음\n   1. 긁어 주기\n");

        if (mouse != 0 && lazer != 0) {
            if (lazer == 2)
                printf("   2. 레이저 포인터로 놀아 주기\n   3. 장난감 쥐로 놀아 주기\n");
            else
                printf("   2. 장난감 쥐로 놀아 주기\n   3. 레이저 포인터로 놀아 주기\n");
        }
        else if (mouse == 0 && lazer == 2)
            printf("   2. 레이저 포인터로 놀아 주기\n");
        else if (mouse == 2 && lazer == 0)
            printf("   2. 장난감 쥐로 놀아 주기\n");

        do {
            printf(">>");
            scanf_s("%d", &a);
        } while (a < 0 || a > toy);
    }
    return 0;
}