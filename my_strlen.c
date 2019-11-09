/*
** ETNA PROJECT, 30/08/2019 by miquel_m
** helicobyte
** File description:
**      renvoie la taille de la string passez en argument
*/
#include "lib.h"
int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
