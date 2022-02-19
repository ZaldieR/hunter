/*
** EPITECH PROJECT, 2020
** help
** File description:
** help
*/

#include <stdio.h>
#include <my.h>

int print_h(int argc, char *str)
{
    if (str[0] == '-' && str[1] == 'h' && argc == 2) {
        my_printf("USAGE:\n\t");
        my_printf("-You need to execute the binary file to launch the game");
        my_printf("\nGAME:\n");
        my_printf("\t-Like the Duck-Hunt game you need to shoot the ducks.\n");
        my_printf("\t-Click on ducks to kill them with your weapon\n");
        my_printf("\t-You will earn points from shoot-them!!\n");
        my_printf("\t-Try to beat the HighScore!!\n");
        return (0);
    }
    return (84);
}