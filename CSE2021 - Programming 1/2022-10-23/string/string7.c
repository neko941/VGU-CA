#include <stdio.h>

int main()
{
    char str[] = "Nyanyame nyanyajyuunyanya-do no nyarabi de nyakunyaku inyanyaku nyanyahan nyanyadai nyanynaku nyarabete nyaganyagame";
    printf("sizeof(str) = %d\n", sizeof(str));

    char *str1 = "Nyanyame nyanyajyuunyanya-do no nyarabi de nyakunyaku inyanyaku nyanyahan nyanyadai nyanynaku nyarabete nyaganyagame";
    printf("sizeof(str1) = %d\n", sizeof(str1));
}