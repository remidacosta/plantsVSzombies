#include "Bouton.h"

#include <cassert>

Bouton::Bouton()
{
    setPosition(Vecteur2D(10,10));
    setDimension(Vecteur2D(100,50));
    setEtat(false);
    setVisible(true);
    setCouleurBouton(sf::Color(100,100,100));

    initTexte();
}

Bouton::Bouton(const Vecteur2D & pos, const Vecteur2D & dim)
{
    assert(pos.getVectX() >= 0);
    assert(pos.getVectY() >= 0);
    assert(dim.getVectX() >= 0);
    assert(dim.getVectY() >= 0);

    setPosition(pos);
    setDimension(dim);
    setEtat(false);
    setVisible(true);
    setCouleurBouton(sf::Color(100,100,100));

    initTexte();
}

bool Bouton::getEtat()const
{
    return etat;
}

void Bouton::setEtat(bool e)
{
    etat = e;
}

bool Bouton::getVisible()const
{
    return visible;
}

void Bouton::setVisible(bool v)
{
    visible = v;

    if(estVisible())
    {
        disparaitreBouton();
    }
    else
    {
        setCouleurBouton(couleurBouton);
    }
}

Vecteur2D Bouton::getPosition()const
{
   return position;
}

void Bouton::setPosition(const Vecteur2D & pos)
{
    assert(pos.getVectX() >= 0);
    assert(pos.getVectY() >= 0);

    position.setVectX(pos.getVectX());
    position.setVectY(pos.getVectY());
    rectBouton.setPosition(sf::Vector2f(pos.getVectX(), pos.getVectY()));

    aligneTxtCentre();
}

Vecteur2D Bouton::getDimension()const
{
    return dimension;
}

void Bouton::setDimension(const Vecteur2D & dim)
{
    assert(dim.getVectX() >= 0);
    assert(dim.getVectY() >= 0);

    dimension.setVectX(dim.getVectX());
    dimension.setVectY(dim.getVectY());
    rectBouton.setSize(sf::Vector2f(dim.getVectX(),dim.getVectY()));

    setTailleCaractere();
    aligneTxtCentre();
}

sf::RectangleShape Bouton::getRectBouton()const
{
    return rectBouton;
}

void Bouton::setRectBouton(const sf::RectangleShape & rect )
{
    rectBouton.setFillColor(rect.getFillColor());
    rectBouton.setOutlineColor(rect.getOutlineColor());
    rectBouton.setOutlineThickness(rect.getOutlineThickness());
    rectBouton.setPosition(rect.getPosition());
    rectBouton.setSize(rect.getSize());
}

void Bouton::setCouleurRectBouton(const sf::Color & color)
{
    rectBouton.setFillColor(color);
}

void Bouton::setCoulContourBouton(const sf::Color & color)
{
    rectBouton.setOutlineColor(color);
    rectBouton.setOutlineThickness(1 + (int)(dimension.getVectX()*dimension.getVectY()/4000));
}

sf::Color Bouton::getCouleurBouton()const
{
    return couleurBouton;
}

void Bouton::setCouleurBouton(const sf::Color & color)
{
    couleurBouton.b = color.b;
    couleurBouton.g = color.g;
    couleurBouton.r = color.r;

    setCouleurRectBouton(color);
}

sf::Text Bouton::getTexte()const
{
    return texteBouton;
}

void Bouton::setTexteBouton(std::string txt)
{
    texteBouton.setString(txt);

    setTailleCaractere();
    aligneTxtCentre();
}

void Bouton::setCouleurTexte(const sf::Color & color)
{
    texteBouton.setFillColor(color);
}

void Bouton::estAppuye()
{
    sf::Color color;
    if(couleurBouton.r != 255)
    {
        color.r = couleurBouton.r + (255-couleurBouton.r)/2;
    }
    else color.r = couleurBouton.r;
    if(couleurBouton.g != 255)
    {
        color.g = couleurBouton.g + (255-couleurBouton.g)/2;
    }
    else color.g = couleurBouton.g;
    if(couleurBouton.b != 255)
    {
        color.b = couleurBouton.b + (255-couleurBouton.b)/2;
    }
    else color.b = couleurBouton.b;

    setCouleurRectBouton(color);
}

void Bouton::estRelache()
{
    sf::Color color;
    color.r = couleurBouton.r;
    color.g = couleurBouton.g;
    color.b = couleurBouton.b;
    setCouleurRectBouton(color);
}

void Bouton::changeEtat()
{
    setEtat((!getEtat()));
}

bool Bouton::curseurEstDessus(int x,int y)
{
    bool result =((position.getVectX() <= x)&&
                  (x <= position.getVectX()+dimension.getVectX())&&
                  (position.getVectY() <= y)&&
                  (y <= position.getVectY()+dimension.getVectY()));

    if(result == true)
    {
        setCoulContourBouton(sf::Color::White);
    }
    else
    {
        setCoulContourBouton(sf::Color::Transparent);
    }

    return result;
}


void Bouton::aligneTxtCentre()
{
    texteBouton.setPosition(  (position.getVectX() + (dimension.getVectX()-texteBouton.getGlobalBounds().width)/2) ,  position.getVectY() + (dimension.getVectY()-texteBouton.getCharacterSize())/4 );
}

void Bouton::setTailleCaractere()
{
    int tchar;
    if(texteBouton.getGlobalBounds().width < rectBouton.getGlobalBounds().width)
    {
        texteBouton.setCharacterSize(2*dimension.getVectY()/3);
    }
    else
    {
        while(texteBouton.getGlobalBounds().width >= 2*rectBouton.getGlobalBounds().width/3)
        {
            tchar = texteBouton.getCharacterSize();
            texteBouton.setCharacterSize(tchar-1);
        }
    }

}

void Bouton::initTexte()
{
    font.loadFromFile("../data/big_noodle_titling.ttf");
    texteBouton.setFont(font);
    texteBouton.setFillColor(sf::Color::White);
    texteBouton.setString("texte");
    setTailleCaractere();

    aligneTxtCentre();
}

bool Bouton::estActif()
{
    return getEtat();
}

bool Bouton::estVisible()
{
    return getVisible();
}

void Bouton::disparaitreBouton()
{
    rectBouton.setFillColor(sf::Color::Transparent);
    rectBouton.setOutlineColor(sf::Color::Transparent);
    texteBouton.setFillColor(sf::Color::Transparent);
}














