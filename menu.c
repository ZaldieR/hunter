/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <ducks.h>
#include <game.h>

void verif_start(sfVector2f mouse, util_t *util)
{
    if (mouse.x >= 290 && mouse.x <= 470 &&
    mouse.y >= 220 && mouse.y <= 300) {
        game_start(util);
    }
}

void event_menu(util_t *util)
{
    sfEvent event;
    sfVector2f mouse;

    while (sfRenderWindow_pollEvent(util->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(util->window);
        if (event.type == sfEvtMouseButtonPressed) {
            mouse.x = event.mouseButton.x;
            mouse.y = event.mouseButton.y;
            verif_start(mouse, util);
        }
    }
}

sfText *set_title(sfClock *clock)
{
    sfText *text  = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfVector2f vec;
    sfColor color;
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    srand(time.microseconds);
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    vec.x = 1.2;
    vec.y = 1.2;
    sfText_setString(text, "Shoot-it!");
    sfText_setFont(text, font);
    sfText_setScale(text, vec);
    sfText_setColor(text, color);
    sfText_setPosition(text, set_vector(300, 130));
    sfText_setRotation(text, (rand() % 20 - 20));
    return (text);
}

sfSprite *make_start(void)
{
    sfTexture *texture = sfTexture_createFromFile("assets/start_1.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, set_vector(280, 220));
    return (sprite);
}

void start_menu(void)
{
    util_t util;
    sfClock *clock = sfClock_create();
    sfTime time;
    float secs;
    sfText *text = set_title(clock);
    sfSprite *sprite = make_start();

    make_util(0, &util);
    draw_menu(&util, text, sprite);
    while (sfRenderWindow_isOpen(util.window)) {
        time = sfClock_getElapsedTime(clock);
        secs = time.microseconds / 1000000.0;
        if (secs >= 0.1) {
            move_background(util.const_sprites);
            draw_menu(&util, text, sprite);
            sfRenderWindow_display(util.window);
            sfClock_restart(clock);
        }
        event_menu(&util);
    }
}