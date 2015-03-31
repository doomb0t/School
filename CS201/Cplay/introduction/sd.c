#include <stdio.h>

// consume rest of line in the input stream
void eatLine ()
{
    while (getchar() != '\n') ;
}

int main (int argc, char **argv)
{
    int     size = 10;
    int     nParsed;
    char    str[10];
    
    printf("type a string: ");
    nParsed = scanf("%*s", 10, str);    // read in string of length <= 8
                                    // (why don't we need an & in front of str?)
    if (nParsed != 1) {             // check we parsed all the items requested
        eatLine();
        printf("error!\n\n");
        }
    else
        printf("you typed \"%s\"\n\n", str);

    return 0;
}
