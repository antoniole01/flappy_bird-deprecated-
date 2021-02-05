#include "pch.h"
#include "c:\z\_MI\colors.h"

//SDL_Rect rect;// = {0,0,100+val,600};

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 33

void input()
{
	while(POLLEVENT)
	{
		if(QUIT) { exit(0); }
			
		if(DOWNPRESS)
		{
			if(ESCAPE) { running = false; }
			if(SPACE)  { }
		}
		if(UPPRESS)
		{
			
		}
	}
}

void cube_draw(double screenpos)
{
	drawFillRect(20,(int)screenpos,50,50,0,0,0,255);
}

void cube_input(double &posy, bool isgrav, double &vel, bool &keyisdown)
{
	if(DOWNPRESS)
	{
		if(!isgrav)
		{
			if(UP)
			{
				vel += 3,0;
				posy += 5 + vel;
				keyisdown = true;
			}
		}
	}
	if(UPPRESS)
	{
		if(UP)
		{
			//vel = 0;
		}
	}
}

void cube_update(double &posy, double &gravity, bool &isgrav, bool &keyisdown)
{
	if(posy >= 100 && isgrav == false)
	{
		isgrav = !isgrav;
		posy -= 5;

	}
	
	if(posy <= 0)
	{
		posy = 0;
		isgrav = false;
	}
	
	if(isgrav)
	{
		posy -= 5;
	}
}

void cube_init()
{
#define G 9.8
	static double posy = 0;
	double screenpos = SCREEN_HEIGHT - 50 - posy;
	double gravity     =     G; //1 //
	double vel         =   0.0; //1 // 0.2
	//double acc         =   0.0;
	//double lift        = -15.0;
	static bool isgrav = false;
	bool keyisdown = false;
	
	cube_draw(screenpos);
	cube_input(posy,isgrav,vel,keyisdown);
	cube_update(posy, gravity, isgrav, keyisdown);
}

void draw()
{
	SDL_SetRenderDrawColor(renderer,SKYBLUE);
	SDL_RenderClear(renderer);

	cube_init();
	
	SDL_RenderPresent(renderer);	
}

int main(int argc, char* args[])
{
	init_Window(300,200,SCREEN_WIDTH,SCREEN_HEIGHT,0,0);
	loading();
	
	while(running)
	{
		input();
		draw();
		SDL_Delay(1000/FPS);
	}

	destroy_Window();
	return(0);
}
