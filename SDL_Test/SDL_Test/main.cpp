#include "SDL.h"

int main(int argc, char* args[]) {
	
	/************************************************************************************
	*							Setup Instructions
	*
	* Add SDL folder to project directory .../projects/SDL_Test/SDL_Test
	* Go to SDL_Test Properties either via solution explorer or Project menu
	* Go to Configuration Properties/VC++ Directories
	* Add include folder from SDL to the Include Directories paths
	* add lib/x86 folder from SDL to the Libraries Directories paths
	* Go to Linker/Input and add SDL2.lib and SDL2main.lib 
	* to the Additional Dependencies list
	* Go to Linker/System and set the SubSystem to Windows
	*
	* Build test code (SDL_Init(SDL_INIT_EVERYTHING), SDL_Quit())
	*
	* After solution is built, go to the debug folder where the .exe is located
	* .../projects/SDL_Test/Debug
	* and copy the SDL2.dll file from lib/x86 folder to the debug folder.
	* 
	* Run debugger and verify that program runs
	*
	*************************************************************************************/

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Quit();

	return 0;
}