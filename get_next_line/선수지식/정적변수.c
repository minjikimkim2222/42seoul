// ex01 -> 정적 지역변수

// #include <stdio.h>

// void increaseNumber()
// {
//     static int num1; // 정적변수 선언 및 초기화 (디폴트 값 : 0)
//     printf("%d\n", num1);
//     num1++; // 정적변수 num1값 1 증가
// }

// int main(void)
// {
//     increaseNumber(); // 0
//     increaseNumber(); // 1
//     increaseNumber(); // 2
//    // printf("%d\n", num1); // num1은 increaseNumber 함수 내에서 선언된 정적 "지역" 변수이므로, 에러!
// }

// ex02 -> 정적 전역변수

/*
아래 코드는 전역변수이나 정적변수로 선언한 num1을 외부 파일 main.c에서 사용한 것
*/

/* 정적변수.c*/

#include <stdio.h>

static int num1 = 10;

void printNumber(){
    printf("%d\n", num1); // 10, 정적 전역변수 값 출력
}

/* main.c */
#include <stdio.h>
extern int num1; 
// extern 키워드로 선언된 외부변수는 "외부 파일[정적변수.c]에 선언된 변수를 참조하는 외부변수"
// 여기서 외부파일에 선언된 변수는 정적 전역 변수이기에, 자신의 파일에서만 접근 가능하기에 컴파일 에러가 난다.

int main(void)
{
    printf("%d\n", num1); // 컴파일 에러
    return (0);
}

