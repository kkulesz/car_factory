#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "factory_manager.h"
int main(){
    sf::RenderWindow window( sf::VideoMode(800,600), "xD");
    window.setFramerateLimit(60);
    sf::CircleShape circle(50.f);
    circle.setFillColor( sf::Color(10,150,21) );
    while( window.isOpen() ){
        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                window.close();
            }
            if( event.key.code == sf::Keyboard::Escape){
                window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(circle);
            window.display();
        }
    }
    /*
    FactoryManager manager;
    manager.produceAllParts();
    if(manager.produceCar(Car::BLACK))
        std::cout<<"tu powinienem byc"<<std::endl;
    if(manager.produceCar(Car::BLUE))
        std::cout<<"tu nie powinienem byc"<<std::endl;
    manager.produceAllParts();
    manager.produceBattery();
    manager.produceEngine();
    if(manager.produceCar(Car::BLACK))
        std::cout<<"tu powinienem byc"<<std::endl;
    if(manager.produceCar(Car::BLUE))
        std::cout<<"tu nie powinienem byc"<<std::endl;
    */
    return 0;
}
