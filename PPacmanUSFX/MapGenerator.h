#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"
#include "Muros.h"


using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;

	const string pathPacman = "Resources/PacMan_1.bmp";
	const string pathFantasma1 = "Resources/Pacmanultimo.bmp";
	const string pathFantasma2 = "Resources/fantasmaamarillo.bmp";
	const string pathFantasma3 = "Resources/azul.png";
	const string pathFantasma4 = "Resources/fantasma.png";
	const string pathFantasma5 = "Resources/fantasmarojo.bmp";
	const string pathFruta = "Resources/frutas2.png";
	const string pathMoneda = "Resources/coint1.png";
	const string pathSuperMoneda = "Resources/mone03.jpeg";
	const string pathPared = "Resources/MuroH.png";
	const string pathfuego = "Resources/fire.jpg";


	Texture* PacmanTexture;
	Texture* fantasmaTexture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* fantasma5Texture;
	Texture* FrutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* MurosTexture;
	Texture* fuegoTexture;
	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
};



