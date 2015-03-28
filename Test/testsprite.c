#include <stdbool.h>
#include "sdl.h"

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
const int SCREEN_BPP=32;

const int SHEET_WIDTH =200;
const int sheet_WIDTh =200;

SDL_Surface*faces=NULL;
SDL_Surface*screen=NULL;

SDL_Event event;

SDL_Rect clip[4];

void apply_surface ( int x, int y, SDL_surface* source ,SDL_Surface* destination ,SDL_Rect* clip = NULL)
{
    SDL_Rect offset;

    offset.x=x ;
    offset.y=y ;

    SDL_BlitSurface(source, clip , destination,&offset);

}
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = SHEET_WIDTH/2;
    clip[ 0 ].h = SHEET_HEIGHT/2;

    clip[ 1 ].x = SHEET_WIDTH/2;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = SHEET_WIDTH/2;
    clip[ 1 ].h = SHEET_HEIGHT/2;

    clip[ 2 ].x = 0;
    clip[ 2 ].y = SHEET_HEIGHT/2;
    clip[ 2 ].w = SHEET_WIDTH/2;
    clip[ 2 ].h = SHEET_HEIGHT/2;


    clip[ 3 ].x = SHEET_WIDTH/2;
    clip[ 3 ].y = SHEET_HEIGHT/2;
    clip[ 3 ].w = SHEET_WIDTH/2;
    clip[ 3 ].h = SHEET_HEIGHT/2;

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

    apply_surface( 0, 0, faces, screen, &clip[ 0 ] );
    apply_surface( SCREEN_WIDTH-(SHEET_WIDTH/2), 0, faces, screen, &clip[ 1 ] );
    apply_surface( 0, SCREEN_HEIGHT-(SHEET_HEIGHT/2), faces, screen, &clip[ 2 ] );
    apply_surface( SCREEN_WIDTH-(SHEET_WIDTH/2), SCREEN_HEIGHT-(SHEET_HEIGHT/2), faces, screen, &clip[ 3 ] );
