/*
** EPITECH PROJECT, 2020
** set
** File description:
** set
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <game.h>
#include <my.h>

void set_textures(sfTexture **textures)
{
    textures[0] = sfTexture_createFromFile("assets/curs_2.png", NULL);
    textures[1] = sfTexture_createFromFile("assets/fond_big.jpg", NULL);
    textures[2] = sfTexture_createFromFile("assets/heart_1.png", NULL);
    textures[3] = sfTexture_createFromFile("assets/heart_empty.png", NULL);
    textures[4] = sfTexture_createFromFile("assets/restart_1.png", NULL);

    textures[5] = sfTexture_createFromFile("assets/ducks.png", NULL);
    textures[6] = sfTexture_createFromFile("assets/ducks_2.png", NULL);
    textures[7] = sfTexture_createFromFile("assets/ducks_black.png", NULL);
    textures[8] = sfTexture_createFromFile("assets/ducks_black_2.png", NULL);
    textures[9] = sfTexture_createFromFile("assets/ducks_red.png", NULL);
    textures[10] = sfTexture_createFromFile("assets/ducks_red_2.png", NULL);
    textures[11] = sfTexture_createFromFile("assets/ducks_red_3.png", NULL);
}

void set_const_sprites(sfSprite **const_sprites, sfTexture **textures)
{
    const_sprites[0] = make_sprite(textures[0]);
    const_sprites[1] = make_sprite(textures[1]);
    const_sprites[2] = make_sprite(textures[4]);
}

void set_sound_buffer(sfSoundBuffer **sound_buffer)
{
    sound_buffer[0] = sfSoundBuffer_createFromFile("assets/sounds/music.wav");
    sound_buffer[1] = sfSoundBuffer_createFromFile("assets/sounds/shoot.wav");
    sound_buffer[2] = sfSoundBuffer_createFromFile("assets/sounds/duck.wav");
}

void set_sounds(sfSoundBuffer **sound_buffer, sfSound **sound)
{
    sound[0] = sfSound_create();
    sound[1] = sfSound_create();
    sound[2] = sfSound_create();
    sfSound_setBuffer(sound[0], sound_buffer[0]);
    sfSound_setBuffer(sound[1], sound_buffer[1]);
    sfSound_setBuffer(sound[2], sound_buffer[2]);
}

sfText *make_text(char *first, int *score)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfColor color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    char *str = my_unatoi(*score);
    sfText_setString(text, my_add_to_str(first, str, my_strlen(str)));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setColor(text, color);
    sfText_setPosition(text, set_vector(100, 550));
    return (text);
}