/*
파일을 읽는 루프를 구현해, 파일의 끝을 만났을 때 루프 종료하는 조건으로,
반환값이 0인지를 확인하는 일반적인 방법

puts함수는 "문자열" 출력함수, 문자열 출력 후 줄바꿈을 시전한다.
*/

#include <stdio.h> // printf, puts
#include <fcntl.h> // O_RDONLY
#include <unistd.h> // read

int main(void)
{
    int fd;
    fd = open("./test.txt", O_RDONLY);

    if (fd == -1){
        perror("error opening the file\n");
        return (1);
    }
    char buff[1024];
    size_t bytesRead;

    while ((bytesRead = read(fd, buff, 5)) > 0){
        buff[bytesRead] = '\0'; // 개행이 아닌 널을 넣어준다.
        puts(buff); 
        printf("\n5바이트씩 읽었다\n"); // debugging
    }

    if (bytesRead == 0)
    {
        // End of file 도달!
        printf("EOF reached\n");
    }
    else if (bytesRead == -1){
        printf("Error reading the file\n");
    }

    close(fd);
}