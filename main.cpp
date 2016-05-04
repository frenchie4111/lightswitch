#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_gfxPrimitives.h>

#include <iostream>
#include <sstream>
#include <ctime>

#include "lyonsSDL.h"

using namespace std;
int main ( int argc, char** argv )
{
    // Start SDL stuff

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit( SDL_Quit );

    TTF_Init();
    TTF_Font *font = TTF_OpenFont( "arial.ttf", 10 );
    int current_size = 10;
    SDL_Color textColor = { 150, 150, 150 };

    SDL_Surface* screen = SDL_SetVideoMode( 240, 320, 16, SDL_HWSURFACE|SDL_DOUBLEBUF/*|SDL_FULLSCREEN*/ );

    // End SDL stuff; start main loop

    // My stuff
    lyons_text th;

    bool done = false;
    while ( !done )
    {
        //SDL_ShowCursor( SDL_DISABLE );
        //Start event (For closing) stuff

        SDL_Event event;
        if( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                done = true;
            }
            if( event.type == SDL_MOUSEBUTTONDOWN ) {
                printf( "Mouse button down" );
                if( event.button.button = SDL_BUTTON_LEFT ) {
                    printf( "Left Mouse Button" );
                }
            }
        }

        //End event stuff; Start input keys

        Uint8 *keystates = SDL_GetKeyState( NULL );
        if( keystates[ SDLK_ESCAPE ] )
        {
            done = true;
        }

        SDL_FillRect( screen, 0, SDL_MapRGB( screen->format, 80, 80, 80 ) );

        int x = 100;
        int y = 100;
        string text = "Test";

        SDL_Surface *message_surface;
        message_surface = TTF_RenderText_Solid( font, text.c_str(), textColor );
        apply_surface( x - ( message_surface->w / 2 ), y, message_surface, screen );
        SDL_FreeSurface( message_surface );

        //End input keys; Start drawing things

        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 40, 40, 40));

        SDL_Flip( screen );
    }

    //End main loop; clean up
    printf("Exited cleanly\n");//*/
    return 0;
}
