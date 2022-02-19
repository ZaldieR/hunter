/*
** EPITECH PROJECT, 2020
** ducks
** File description:
** ducks
*/

#include <SFML/Graphics.h>

#ifndef __DUCKS_H__
#define __DUCKS_H__

#define NB_DUCKS 10

typedef struct duck_s
{
    sfSprite *sprite;
    sfVector2f init_position;
    sfVector2f movement;
    sfIntRect rect;
    int points;
} duck_t;

#endif