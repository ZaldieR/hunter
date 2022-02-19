/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <graphics.h>
#include <ducks.h>

#ifndef __GAME_H__
#define __GAME_H__

typedef struct util_s
{
    sfRenderWindow *window;
    sfEvent event;
    sfTime time;
    sfClock *clock;
    int score;
    char *str;
    sfText *text;
    char *filepath;
    sfText *high_score;
    int high;
    int fd;
    sfTexture *textures[12];
    sfSprite *const_sprites[3];
    int nb_lives;
    sfSprite *lives[3];
    sfVector2f lives_pos;
    int game_mode;
    sfSoundBuffer *sound_buffer[3];
    sfSound *sounds[3];
} util_t;

sfRenderWindow *create_window(int width, int height, char *title, int bpp);
void game_start(util_t *util);
void start_menu(void);
int print_h(int argc, char *str);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfVector2f set_vector(int x, int y);
sfIntRect def_rect(int top, int left, int width, int height);
sfSprite *make_sprite(sfTexture *texture);
void draw_scene(util_t *util, duck_t *ducks);
void move_ducks(duck_t *ducks, util_t *util);
void move_background(sfSprite **const_sprites);
void init_duck(int i, sfTexture **textures, duck_t *ducks);
int analyse_events(sfRenderWindow **window, sfEvent event,
util_t *util, duck_t *ducks);
void set_textures(sfTexture **textures);
void set_const_sprites(sfSprite **const_sprites, sfTexture **textures);
sfText *make_text(char *first, int *score);
void make_util(int i, util_t *util);
void verif_ducks(duck_t *ducks, int mouse_x, int mouse_y,
util_t *util);
void set_sound_buffer(sfSoundBuffer **sound_buffer);
void set_sounds(sfSoundBuffer **sound_buffer, sfSound **sound);
void draw_menu(util_t *util, sfText *text, sfSprite *sprite);

#endif