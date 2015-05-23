
#include "prototypes.h"
#include "defs.h"

SDL_Window *screen;
SDL_Renderer *renderer;

void Init()
{
HP = 50;
srand(time(NULL));

spawnTimer = 0.0f;

ennemiList = lList_create();
bulletList = lList_create();

lList_Show(ennemiList, "ennemi");
UpdateHPText();
}
SDL_Renderer *getrenderer(void)
{
    return renderer;
}

 //initialisation de la SDL2 et des libs
void init(char *title)
{

    BASE_LIFE_BUILDING = 50;
srand(time(NULL));

spawnTimer = 0.0f;

ennemiList = lList_create();
bulletList = lList_create();

lList_Show(ennemiList, "ennemi");
UpdateHPText();

    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);

    //On cr�e un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    // Si on n'y arrive pas, on quitte en enregistrant l'erreur dans stdout.txt
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode �cran � %d x %d: %s\n", SCREEN_WIDTH,
                                                                    SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu �tre initialis�e! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }

    //On initialise SDL_TTF 2 qui g�rera l'�criture de texte
    if (TTF_Init() < 0)
    {
        printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
        exit(1);
    }

    //On initialise SDL_Mixer 2, qui g�rera la musique et les effets sonores
    int flags = MIX_INIT_MP3;
    int initted = Mix_Init(flags);
    if ((initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init SDL_Mixer\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    /* Open 44.1KHz, signed 16bit, system byte order,
    stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos) */
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }

    // D�finit le nombre de pistes audio (channels) � mixer
    Mix_AllocateChannels(32);

}


 //On lib�re la m�moire
void cleanup()
{
    //On quitte SDL_Mixer 2 et on d�charge la m�moire
    Mix_CloseAudio();
    Mix_Quit();

    //On fait le m�nage et on remet les pointeurs � NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    //On quitte SDL_TTF 2
    TTF_Quit();

    //On quitte la SDL
    SDL_Quit();

    //Nettoie la map
    cleanMaps();
}


void loadGame()
{
    initMaps();
}
