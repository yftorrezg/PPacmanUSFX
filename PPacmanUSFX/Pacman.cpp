#include <stdio.h>
#include "Pacman.h"

Pacman::Pacman()
{
	// Inicializa propiedade de de pacman
	posicionX = 100;
	posicionY = 100;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 25;
	alto = 25;
	anchoPantalla = 640;
	altoPantalla = 480;
}

Pacman::Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

Pacman::Pacman(int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

Pacman::Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Surface* _pacmanSurface)
{
	// Inicializa propiedade de de pacman
	posicionX = 100;
	posicionY = 100;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = 5;
	ancho = 25;
	alto = 25;
	anchoPantalla = 640;
	altoPantalla = 480;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	pacmanSurface = _pacmanSurface;
}

Pacman::Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Surface* _pacmanSurface, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	pacmanSurface = _pacmanSurface;
}

Pacman::Pacman(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _pacmanTexture, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade de de pacman
	posicionX = _posicionX;
	posicionY = _posicionY;
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	ancho = 25;
	alto = 25;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	pacmanTexture = _pacmanTexture;
}


void Pacman::handleEvent(SDL_Event& e)
{
	// Si se ha precionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		// Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY -= velocidadPatron; break;
		case SDLK_DOWN: velocidadY += velocidadPatron; break;
		case SDLK_LEFT: velocidadX -= velocidadPatron; break;
		case SDLK_RIGHT: velocidadX += velocidadPatron; break;
		}
	}
	// Si se ha soltado una tecla
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		// Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY += velocidadPatron; break;
		case SDLK_DOWN: velocidadY -= velocidadPatron; break;
		case SDLK_LEFT: velocidadX += velocidadPatron; break;
		case SDLK_RIGHT: velocidadX -= velocidadPatron; break;
		}
	}
	//move();
}

void Pacman::move()
{
	// Mueve pacman a la izquierda o a la derecha
	posicionX += velocidadX;

	// Se verifica que no se sobrepasen los bordes horizontales de los margenes establecidos para la pantalla
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{
		// mover atraz
		posicionX -= velocidadX;
	}

	// Mover pacman arriba o abajo
	posicionY += velocidadY;

	// Se verifica que no se sobrepasen los bordes verticales de los margenes establecidos para la pantalla
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// mover atra
		posicionY -= velocidadY;
	}
}

void Pacman::render()
{

	//Color key image
	//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(pacmanSurface->format, 0, 0xFF, 0xFF));

	//SDL_Texture* newTexture = nullptr;

	//newTexture = SDL_CreateTextureFromSurface(renderer, pacmanSurface);
	//if (newTexture == NULL)
	//{
	//	cout << "No se puede crear la textura a partir de la superficie, SDL Error: " << SDL_GetError() << endl;
	//}
	//else
	//{
	//	// Obtener dimensiones de la imagen
	//	ancho = pacmanSurface->w;
	//	alto = pacmanSurface->h;
	//}

	//SDL_Rect* clip = NULL;
	//double angle = 0.0;
	//SDL_Point* center = NULL;
	//SDL_RendererFlip flip = SDL_FLIP_NONE;

	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Set clip rendering dimensions
	/*if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/

	//Render to screen
	SDL_RenderCopyEx(renderer, pacmanTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
