#include "system.h"

System::System()
{
	step("[System] Initializing Fonts.");
	if (TTF_Init() < 0)
		errorSDL("Couldn't Initialize SDL Fonts.", TTF_GetError());

	step("[System] Initializing Audio.");
	
	const int frequency = 44100;
	const int channels = 2;
	const int chunksize = 4096;
	
	if(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, chunksize) < 0)
		errorSDL("Couldn't Initialize SDL Audio.", SDL_GetError());

	step("[System] Initializing SDL.");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		errorSDL("Couldn't Initialize SDL Video.", SDL_GetError());
}

System::~System()
{
	step("[System] Destroying.");
	
	Mix_CloseAudio();
	Mix_Quit();

	TTF_Quit();
	
	SDL_Quit();
}