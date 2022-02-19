/*
** EPITECH PROJECT, 2020
** make_utilities
** File description:
** make_utilities
*/

#include <SFML/Graphics.h>
#include <ducks.h>
#include <game.h>

sfSprite *make_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value)
        rect->left = 0;
    else
        rect->left = rect->left + offset;
}

sfVector2f set_vector(int x, int y)
{
    sfVector2f movement;
    movement.x = x;
    movement.y = y;
    return (movement);
}

sfIntRect def_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}