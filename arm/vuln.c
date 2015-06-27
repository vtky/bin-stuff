#include <stdio.h>
#include <stdlib.h>

void vulnerable(char *buffer)
{
        char buf[10];
        strcpy(buf, buffer);
}

int main(int argc, char **argv)
{
        vulnerable(argv[1]);
        return(0);
}
