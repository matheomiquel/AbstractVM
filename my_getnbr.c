/*
** ETNA PROJECT, 30/08/2019 by miquel_m
** helicobyte
** File description:
**      récupere un nombre
*/
#include "lib.h"

int my_getnbr(char *str)
{
    int number = 0;

    for (int i = 0;str[i] != '\0';i++) {
        number *= 10;
        number += str[i] - 48;
    }
    return number;
}
