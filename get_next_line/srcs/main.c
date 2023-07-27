#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    char* line;

    int fd;
    int i = 1; // 읽은 라인을 표시하기 위해 추가한 변수
    
    fd = open("test.txt", O_RDONLY);

    // fd = 0; -> 이렇게 하면 표준 입력도 가능하다는 사실!
    while (line = get_next_line(fd)) // get_next_line함수가 0을 리턴했다는 건, 다 읽었다는 뜻이다!
    {
        printf("gnl %d line : %s", i++, line);
        free(line);
        // 메모리 할당된 line 출력 후, 해당 메모리를 해제를 한 다음,
        // 다시 안전하게 사용할 수 있게씀!
        // 만일, free없이 반복문을 돌려 line을 재사용할 경우,
        // 이미 해제된 메모리 공간을 가리키게 되어 메모리 누수 가능!
    }
    printf("\nend\n");

    free(line);
    close(fd);

}