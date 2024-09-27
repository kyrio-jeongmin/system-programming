#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

#define INITIAL_SIZE 10

void searchPhoneNumber(char phone[][15], int count) {
    char search[15];
    printf("검색할 전화번호를 입력하세요 : ");
    scanf("%s", search);

    int found =0;
    for(int i =0; i<count; i++) {
       if(strcmp(phone[i], search)==0){
          printf("전화번호 %s이 (가) %d번째에 있습니다.\n", phone[i], i+1);
          found = 1;
          break;
       }
    }

    if(!found) {
       printf("전화번호 %s을(를) 찾을 수 없습니다. \n", search);
    }
}

void deletePhoneNumber(char phone[][15], int *count) {
    char delete[15];
    printf("삭제할 전화번호를 입력하세요 : ");
    scanf("%s", delete);

    int found = -1;
    for (int i=0; i < *count; i++) {
        if (strcmp(phone[i], delete) == 0) {
           found = i;
           break;
        }
    }

    if (found != -1) {
       strcpy(phone[found], phone[*count - 1]);
       (*count)--;
       printf("전화번호 %s가 삭제되었습니다.\n", delete);
    } else {
        printf("전화번호 %s를 찾을 수 없어 삭제할 수 없습니다.\n", delete);
    }
}

int main() {
    char (*phone)[15];
    int size = INITIAL_SIZE;
    int count = 0;

    phone = malloc(size * sizeof(*phone));
    if (phone == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("전화번호 입력 프로그램\n");

    while (count < size) {
        printf("%d번째 전화번호를 입력하세요 (예 : 010-1234-5678) : ", count + 1);
        scanf("%s", phone[count]);
        count++;

        if (count < size) {
            char choice;
            printf("더 입력하시겠습니까? [y/n] : ");
            scanf(" %c", &choice);
            if (choice == 'n' || choice == 'N') {
                break;
            }
       }
    }

    char option;
    do {
        printf("\n원하는 기능을 선택하세요 :\n");
        printf("1. 전화번호 검색\n");
        printf("2. 전화번호 삭제\n");
        printf("3. 전화번호 목록 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                searchPhoneNumber(phone, count);
                break;
            case '2':
                deletePhoneNumber(phone, &count);
                break;
            case '3':
                printf("\n입력된 전화번호 :\n");
                for (int i = 0; i < count; i++) {
                    printf("%d: %s\n", i + 1, phone[i]);
                }
                break;
            case '4':
                printf("프로그램을 종료합니다.\n");
                break;
            defalut:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }while (option != '4');

    free(phone);

    return 0;

}
