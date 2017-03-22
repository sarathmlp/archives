#include <stdio.h>
#include <stdint.h>

struct mem
{
    uint32_t var1;
    uint32_t var2;
    uint16_t var3;
    uint32_t var4;
};

int main()
{
    struct mem var;

    var.var1 =1; 
    var.var2 =2; 
    var.var3 =3; 
    var.var4 =4; 

    printf("%d\n", var.var1);
    printf("%d\n", var.var2);
    printf("%d\n", var.var3);
    printf("%d\n", var.var3);
    return 0;
}
