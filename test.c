#include <stdio.h>
#include <string.h>
int main()
{
char csrc[100] = "Geeksfor";
memcpy(csrc+5, csrc, strlen(csrc)+1);
printf("%s\n", csrc);

char csrc2[100] = "Geeksfor";
memmove(csrc+5, csrc2, strlen(csrc2)+1);
printf("%s\n", csrc2);
return 0;
}
