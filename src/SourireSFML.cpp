#include <SFML/Graphics.hpp>
#include "SmileyVue.h"
#include "MagicienVue.h"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
    RenderWindow fenetre(VideoMode(800, 600), "SFML !");

    //SmileyVue smileyVue(300,200);
    MagicienVue magicienVue(400,400);

    // https://apod.nasa.gov/apod/ap171114.html
    string cheminImageEspace = "decoration/images/DeepPleiadesPanstarrs.jpg";
    Texture ambianceEspace;
    Sprite * scene = NULL;
    if(ambianceEspace.loadFromFile(cheminImageEspace))
    {
    	scene = new Sprite(ambianceEspace);
    }

    float pas = 10;

    while (fenetre.isOpen())
    {
        Event evenement;
        while (fenetre.pollEvent(evenement))
        {
            if (evenement.type == Event::Closed)
                fenetre.close();

            if(evenement.type == Event::KeyPressed)
            {
            	switch(evenement.key.code)
            	{
            		case Keyboard::A:
            			cout << "Touche A" << endl;
            		break;
            		case Keyboard::Left:
            			magicienVue.deplacer(-pas, 0);
               		break;
            		case Keyboard::Right:
            			magicienVue.deplacer(pas, 0);
                   	break;
            		case Keyboard::Up:
            			magicienVue.deplacer(0, -pas);
                   	break;
            		case Keyboard::Down:
            			magicienVue.deplacer(0, pas);
                  	break;
            	}
            }
        }
        fenetre.clear();
        if(scene) fenetre.draw(*scene);
        //smileyVue.afficher(fenetre);
        magicienVue.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}


