/*
지역변수 예제 관찰!
*/

// ex01
// #include <stdio.h>

// void increaseNumber()
// {
//     int num1 = 0; // 변수 선언 및 값 초기화

//     printf("%d\n", num1);
//     num1++;
// }

// int main(void)
// {
//     increaseNumber(); // 0
//     increaseNumber(); // 0
//     increaseNumber(); // 0

//     return (0);
// }
/*
increaseNumber함수 안에서 선언된 num1은 지역변수라, 해당 함수를 벗어나면 값이 사라지며,
다시 increaseNumber를 호출했을 때, 이전 결과와 상관없이 새로운 변수가 생성되기에 increseNumber를 여러 번 호출해보면 0이 출력됨
*/

// ex02
#include <stdio.h>

void print(int a, int b)
{
    printf("%d %d\n", a ,b);
}

int main(void)
{
    int a = 10, b = 20;

    printf("%d %d\n", a, b);
    print(30,40);
    return (0);
}
/*
main의 지역변수 a,b와 printf함수의 매개변수[지역변수] a,b는 서로 영향을 끼치지 않는 지역적으로 전혀 다른 변수다.
각각 main함수의 중괄호 지역, print함수의 중괄호에서 별개로 실행된다.
지역(중괄호)에소 메모리를 생성하고, 해당 지역을 빠져나가면(중괄호 탈출), 메모리가 자동 소멸된다.

*/