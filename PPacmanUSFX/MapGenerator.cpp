#include "MapGenerator.h"


MapGenerator::MapGenerator(int _anchoPantalla, int _altoPantalla)
{
	
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	PacmanTexture = new Texture();
	PacmanTexture->loadFromImage(pathPacman);
	fantasmaTexture = new Texture();
	fantasmaTexture->loadFromImage(pathFantasma1);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	fantasma5Texture = new Texture();
	fantasma5Texture->loadFromImage(pathFantasma5);
	FrutaTexture = new Texture();
	FrutaTexture->loadFromImage(pathFruta);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);

	MurosTexture = new Texture();
	MurosTexture->loadFromImage(pathPared);

	fuegoTexture = new Texture();
	fuegoTexture->loadFromImage(pathfuego);
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* newObject = nullptr;

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				newObject = new Muros(MurosTexture, x * 30, y * 30, 25, 25, anchoPantalla, altoPantalla);
				break;
			case '.':
				newObject = new Moneda(monedaTexture, x * 30, y * 30, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(4);
				break;
			case 'p':
				newObject = new Pacman(PacmanTexture, x * 25, y  * 25 , 25, 25, anchoPantalla, altoPantalla, 5, 0, 0);
				newObject->setParametrosAnimacion(3);
				break;
			case 'b':
				newObject = new Fantasma(fantasmaTexture, x*25, y*25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(4);
				break;
			case 'a':
				newObject = new Fantasma(fantasma2Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(4);
				break;
			case 'c':
				newObject = new Fantasma(fantasma3Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(4);
				break;
			case 'd':
				newObject = new Fantasma(fantasma4Texture, x * 26, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(4);
				break;
			case 'e':
				newObject = new Fantasma(fantasma5Texture, x * 26, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(4);
				break;
			case 'q':
				newObject = new Muros(fuegoTexture, x * 30, y * 30, 25, 48, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(4);
				break;
			case 'f':
				newObject = new Fruta(FrutaTexture,x*30, y*30 , 25, 25, anchoPantalla, altoPantalla);
				int i = rand() % 8;
				newObject->setPosicionexpecifica(25*i);
				break;
			}

			// If the object was created, add it to the vector
			if (newObject != NULL)
				vectorObjetosJuego.push_back(newObject);
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}
}