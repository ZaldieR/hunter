/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/

#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ducks.h>
#include <game.h>
#include <my.h>

void set_pos_cursor(util_t *util)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(util->window);
    sfVector2f mousef;

    mousef.x = mouse.x - 13;
    mousef.y = mouse.y - 13;
    sfSprite_setPosition(util->const_sprites[0], mousef);
}

void draw_scene_first(util_t *util, duck_t *ducks)
{
    sfVector2f lives_pos = set_vector(600, 550);

    set_pos_cursor(util);
    for (int i = 0; i < NB_DUCKS; i++)
        sfRenderWindow_drawSprite(util->window, ducks[i].sprite, NULL);
    for (int i = 0; i < 3; i++) {
        lives_pos.x += 40;
        sfSprite_setPosition(util->lives[i], lives_pos);
        sfRenderWindow_drawSprite(util->window, util->lives[i], NULL);
    }
    sfRenderWindow_drawSprite(util->window, util->const_sprites[0], NULL);
    sfRenderWindow_drawText(util->window, util->text, NULL);
}

void draw_scene_second(util_t *util, duck_t *ducks)
{
    sfVector2f duck_place = set_vector(-100, 50);

    set_pos_cursor(util);
    if (util->high < util->score) {
        util->fd = open(util->filepath, O_WRONLY);
        util->str = my_unatoi(util->score);
        util->high_score = make_text("High Score:", &util->score);
        write(util->fd, util->str, my_strlen(util->str));
        close(util->fd);
    }
    for (int i = 0; i < NB_DUCKS; i++)
        sfSprite_setPosition(ducks[i].sprite, duck_place);
    sfText_setPosition(util->text, set_vector(320, 150));
    sfRenderWindow_drawText(util->window, util->text, NULL);
    sfText_setPosition(util->high_score, set_vector(290, 100));
    sfRenderWindow_drawText(util->window, util->high_score, NULL);
    sfSprite_setPosition(util->const_sprites[2], set_vector(290, 270));
    sfRenderWindow_drawSprite(util->window, util->const_sprites[2], NULL);
    sfRenderWindow_drawSprite(util->window, util->const_sprites[0], NULL);
}

void draw_menu(util_t *util, sfText *text, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(util->window, util->const_sprites[1], NULL);
    sfRenderWindow_drawSprite(util->window, sprite, NULL);
    sfRenderWindow_drawText(util->window, text, NULL);
}

void draw_scene(util_t *util, duck_t *ducks)
{
    sfRenderWindow_drawSprite(util->window, util->const_sprites[1], NULL);
    if (util->game_mode == 1) {
        sfRenderWindow_setMouseCursorVisible(util->window, sfFalse);
        draw_scene_first(util, ducks);
    } else {
        sfRenderWindow_setMouseCursorVisible(util->window, sfFalse);
        draw_scene_second(util, ducks);
    }
    sfRenderWindow_display(util->window);
}