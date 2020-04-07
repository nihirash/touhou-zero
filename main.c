#include <evo.h>
#include "resources.h"

#include "sprite_pool.c"
#include "gameloop.c"
#include "gameover.c"
#include "menu.c"
#include "dialogs.c"
#include "win_stage.c"

void intro()
{
	unpack_pal256(PAL256_TITLE, 0);
	draw_image_g256(0, 0, IMG256_TITLE);
	text_x = 11;
	text_y = 25;
	put_slow_str("This is party version!");
	text_y += 2;
	text_x = 12;
	put_slow_str("Press SPACE to start");
	while (!keys[FIRE])
	{
		keyboard(keys);
		swap_screen();
	}
	for (cnt = BRIGHT_MID; cnt > BRIGHT_MIN; cnt--)
	{
		pal_bright(cnt);
		swap_screen();
	}
}

void state_manager()
{
	while (TRUE)
	{
		music_stop();
		sprites_stop();
		switch (state)
		{
		case STATE_PLAY:
			start_game_loop();
			break;
		case STATE_MENU:
			init_menu_loop();
			break;
		case STATE_GAMEOVER:
			gameover();
			break;
		case STATE_WIN:
			win_stage();
			break;
		default:
			break;
		}
	}
}

void main(void)
{
	// Порт 0x20AF - порт управления скоростью CPU. Значение 6 - это 14МГц и включенный кэш(0110)
	__asm 
	ld bc, #0x20af 
	ld a, #6 
	out(c), a 
	__endasm;
	set_screen_sync(1);
	set_res(MODE320X240);
	pal_bright(BRIGHT_MID);
	intro();
	scroll(0, 0);
	init_pool();
	state = STATE_MENU;
	state_manager();
}