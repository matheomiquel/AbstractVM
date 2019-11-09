/*
** ETNA PROJECT, 30/08/2019 by miquel_m
** helicobyte
** File description:
**      concataine la chaine src dans la chaine dest
*/
#include "lib.h"
char *my_strcat(char *dest,const char *src)
{
    int i;
    int a = (my_strlen(dest));
    for (i = 0; src[i] != '\0'; i++) {
        dest[a + i] = src[i];
    }
    dest[a + i] = '\0';
    return (dest);
}
