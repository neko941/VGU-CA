#include <stdio.h>

int main()
{
    const char *str = "neko941";
    printf("%s\n", str);

    str = "neko941";
    printf("%s\n", str);

    str[0] = 'N';
    printf("%s", str);
}