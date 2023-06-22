#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1 = ft_printf("my_ans : \001\002\007\v\010\f\r\n");
    printf("\n절취선\n");
    int ret2 = printf("answer : \001\002\007\v\010\f\r\n");
    printf("\nret1 : %d, ret2 : %d\n", ret1, ret2);
}