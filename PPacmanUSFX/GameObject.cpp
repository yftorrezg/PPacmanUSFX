#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;

GameObject::GameObject(int _posicionX, int _posicionY, 
	int _ancho, int _alto, int _anchoPantalla, 
	int _altoPantalla,Texture* _texturas, int _posicionXTextura, int _posicionYTextura) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	texturas = _texturas;
	posicionXTextura = _posicionXTextura;
	posicionYTextura = _posicionYTextura;

	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
	
}

void GameObject::renderObjetos() {
	
	if (visible) {
		SDL_Rect renderQuad = { 25 * numeroFrame+posicionXTextura  , posicionYTextura, ancho, alto };
		//Render to screen
		texturas->render(posicionX, posicionY, &renderQuad);
	}
};

void GameObject::handleEvent(SDL_Event& e) {};

void GameObject::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 7;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}