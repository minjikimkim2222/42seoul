// #include <stdio.h>

// int global = 100;

// int main(void)
// {
//     printf("%d\n", global);
//     return (0);
// }

/* <기초 전역변수 예제>
전역변수는 메모리 생성시점이 프로그램의 시작, 소멸 시점이 프로그램의 종료이다.
그렇기에 프로그램이 실행되는 동안에는 어디든지 접근해서 사용 가능!
*/

// 다음은 전역변수의 특징을 보여주는 예시. 어느 함수든지 접근해서 사용 가능!
#include <stdio.h>

void add();
int global;

int main(void){
    printf("%d\n", global);
    add();
    printf("%d\n", global);
    return (0);
}

void add(){
    global += 100;
}