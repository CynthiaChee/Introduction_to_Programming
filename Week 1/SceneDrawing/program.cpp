#include "splashkit.h"

//Bitmaps are self-drawn.
// Sound effects obtained from https://www.zapsplat.com*/
// Video link: https://2006242.kaf.kaltura.com/media/t/1_1vpeyrsl
// (Alternative Link): https://drive.google.com/file/d/1hkg1-eyrJzeDJiKS5tjCp47sr3-HeB7T/view?usp=sharing

void mouseclick()
{
load_sound_effect("mouseclick", "mouseclick.wav");
play_sound_effect("mouseclick");
}

void womansigh()
{
load_sound_effect("womansigh", "womansigh.wav");
play_sound_effect("womansigh");
}

void pop()
{
load_sound_effect("pop", "pop.wav");
play_sound_effect("pop");
}

void punch()
{
load_sound_effect("punch", "punch.wav");
play_sound_effect("punch");
}

void typing()
{
load_sound_effect("typing", "typing.wav");
play_sound_effect("typing");
}
int main()
{
    open_window("SceneDrawing", 800, 800);
    load_bitmap("intro", "intro.png");
    clear_screen(COLOR_RED);
    draw_bitmap("intro", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(3000);

    clear_screen(COLOR_RED);
    load_bitmap("what_grandparents", "what_grandparents.png");
    draw_bitmap("what_grandparents", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("silence", "silence.png");
    draw_bitmap("silence", 0, 0);
    refresh_screen(60);
    delay(1500);
    
    clear_screen(COLOR_RED);
    load_bitmap("question1", "question1.png");
    draw_bitmap("question1", 0, 0);
    womansigh();
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("question2", "question2.png");
    draw_bitmap("question2", 0, 0);
    womansigh();
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("silence", "silence.png");
    draw_bitmap("silence", 0, 0);
    refresh_screen(60);
    delay(1500);

    clear_screen(COLOR_RED);
    load_bitmap("question3", "question3.png");
    draw_bitmap("question3", 0, 0);
    load_sound_effect("malehuh", "malehuh.wav");
    play_sound_effect("malehuh");
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("what_parents", "what_parents.png");
    draw_bitmap("what_parents", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("fix1", "fix1.png");
    draw_bitmap("fix1", 0, 0);
    pop();
    refresh_screen(60);
    delay(1000);

    clear_screen(COLOR_RED);
    load_bitmap("fix2", "fix2.png");
    draw_bitmap("fix2", 0, 0);
    pop();
    refresh_screen(60);
    delay(1000);

    clear_screen(COLOR_RED);
    load_bitmap("fix3", "fix3.png");
    draw_bitmap("fix3", 0, 0);
    pop();
    refresh_screen(60);
    delay(1000);

    clear_screen(COLOR_RED);
    load_bitmap("fix4", "fix4.png");
    draw_bitmap("fix4", 0, 0);
    pop();
    refresh_screen(60);
    delay(1000);

    clear_screen(COLOR_RED);
    load_bitmap("rebel1", "rebel1.png");
    draw_bitmap("rebel1", 0, 0);
    punch();
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("rebel2", "rebel2.png");
    draw_bitmap("rebel2", 0, 0);
    punch();
    load_sound_effect("ugh", "ugh.wav");
    play_sound_effect("ugh");
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("what_friends", "what_friends.png");
    draw_bitmap("what_friends", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("game1", "game1.png");
    draw_bitmap("game1", 0, 0);
    load_sound_effect("game", "game.wav");
    play_sound_effect("game");
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("game2", "game2.png");
    draw_bitmap("game2", 0, 0);
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("game3", "game3.png");
    draw_bitmap("game3", 0, 0);
    load_sound_effect("ugh", "ugh.wav");
    play_sound_effect("ugh");
    refresh_screen(60);
    delay(3000);

    clear_screen(COLOR_RED);
    load_bitmap("what_i_think", "what_i_think.png");
    draw_bitmap("what_i_think", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(1500);

    clear_screen(COLOR_RED);
    load_bitmap("what_i_think_two", "what_i_think_two.png");
    draw_bitmap("what_i_think_two", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(1500);

    clear_screen(COLOR_RED);
    load_bitmap("cool1", "cool1.png");
    draw_bitmap("cool1", 0, 0);
    load_sound_effect("bgm", "bgm.wav");
    play_sound_effect("bgm");
    typing();
    refresh_screen(60);
    delay(4000);

    clear_screen(COLOR_RED);
    load_bitmap("cool2", "cool2.png");
    draw_bitmap("cool2", 0, 0);
    typing();
    refresh_screen(60);
    delay(4000);

    clear_screen(COLOR_RED);
    load_bitmap("cool3", "cool3.png");
    draw_bitmap("cool3", 0, 0);
    typing();
    refresh_screen(60);
    delay(4000);

    clear_screen(COLOR_RED);
    load_bitmap("what_i_do", "what_i_do.png");
    draw_bitmap("what_i_do", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("run", "run.png");
    draw_bitmap("run", 0, 0);
    load_sound_effect("keypress", "keypress.wav");
    play_sound_effect("keypress");
    refresh_screen(60);
    delay(2500);

    clear_screen(COLOR_RED);
    load_bitmap("error1", "error1.png");
    draw_bitmap("error1", 0, 0);
    load_sound_effect("fail", "fail.wav");
    play_sound_effect("fail");
    refresh_screen(60);
    delay(5000);

    clear_screen(COLOR_RED);
    load_bitmap("error2", "error2.png");
    draw_bitmap("error2", 0, 0);
    load_sound_effect("censor", "censor.wav");
    play_sound_effect("censor");
    refresh_screen(60);
    delay(2000);

    clear_screen(COLOR_RED);
    load_bitmap("last", "last.png");
    draw_bitmap("last", 0, 0);
    mouseclick();
    refresh_screen(60);
    delay(3000);

    return 0;
}