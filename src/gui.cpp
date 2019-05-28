#include <iostream>
#include "gui.h"

#define HEIGHT 768
#define WIDTH 1024

Interface::Interface(){
    window_ = new sf::RenderWindow( sf::VideoMode( WIDTH, HEIGHT ), "title", sf::Style::Close | sf::Style::Titlebar);

    font_.loadFromFile( "src/fonts/SulphurPoint-Regular.otf" );
    stateMessege_.setFont( font_);
    stateMessege_.setPosition( sf::Vector2f(400.0f, 100.0f) );
    stateMessege_.setCharacterSize( 100 );
    stateMessege_.setFillColor( sf::Color(0,0,0) );//BLACK
    updateStateMessege_();

    actionMessege_.setFont( font_ );
    actionMessege_.setPosition( sf::Vector2f( 200.0f, 20.0f) );
    actionMessege_.setCharacterSize( 40 );
    actionMessege_.setFillColor( sf::Color(0,0,0) );//BLACK

    setButtons_();
}

Interface::~Interface(){
    delete carFactoryButton_;
    delete frameFactoryButton_;
    delete engineFactoryButton_;
    delete batteryFactoryButton_;
    delete window_;
}

void Interface::mainLoop(){
    while( window_->isOpen() ){
        sf::Event evnt;

        while( window_->pollEvent(evnt) ){
            switch( evnt.type){

            case sf::Event::KeyPressed:
                if( evnt.key.code == sf::Keyboard::Escape){
                    window_->close();
                }
                break;

            case sf::Event::Closed:
                window_->close();
                break;

            case sf::Event::MouseButtonPressed:
                mousePressedEvents_();
                break;

            case sf::Event::MouseButtonReleased:
                mouseReleasedEvents_();
                break;

            default:
                break;
            }
        }
        window_->clear( sf::Color(255,255,255) );// WHITE
        this->drawButtons_();
        this->drawTexts_();
        window_->display();
    }
}

void Interface::setButtons_(){
    float XPosition = 20.0f;
    float YPosition = 20.0f;
    sf::Vector2f buttonSize( 150.0f, 150.0f );
    carFactoryButton_ = new Button( "src/images/car.jpeg", buttonSize, sf::Vector2f( XPosition, YPosition + 0.0f ));
    frameFactoryButton_ = new Button( "src/images/frame.jpg", buttonSize, sf::Vector2f( XPosition, YPosition + 190.0f));
    engineFactoryButton_ = new Button( "src/images/engine.jpeg", buttonSize, sf::Vector2f( XPosition, YPosition + 380.0f));
    batteryFactoryButton_ = new Button( "src/images/battery.jpg", buttonSize, sf::Vector2f( XPosition, YPosition + 570.0f));
}

void Interface::drawButtons_(){
    carFactoryButton_->draw( window_ );
    frameFactoryButton_->draw( window_);
    engineFactoryButton_->draw( window_);
    batteryFactoryButton_->draw( window_);
}

void Interface::drawTexts_(){
    window_->draw( stateMessege_ );
    window_->draw( actionMessege_ );
}

void Interface::mousePressedEvents_(){
    setActionMessege_("");//clears actionMessege_
    checkButtons_();
}

void Interface::checkButtons_(){
    if( carFactoryButton_->isClicked( window_ ) ){
        actionOfCarFactoryButton();
    }
    else if( frameFactoryButton_->isClicked( window_ ) ){
        actionOfFrameFactoryButton();
    }
    else if( engineFactoryButton_->isClicked( window_ ) ){
        actionOfEngineFactoryButton();
    }
    else if( batteryFactoryButton_->isClicked( window_ ) ){
        actionOfBatteryFactoryButton();
    }

}

void Interface::actionOfCarFactoryButton(){
    if( factoryManager_.produceCar() ){
        setActionMessege_( "Car produced" );
        carFactoryButton_->setColor( sf::Color::Green );
    }else{
        setActionMessege_( "Not enough parts to produce a car.");
        carFactoryButton_->setColor( sf::Color::Red );
    }
}

void Interface::actionOfFrameFactoryButton(){
    frameFactoryButton_->setColor( sf::Color::Green );
    factoryManager_.produceFrame();
    setActionMessege_( "Frame produced" );
}

void Interface::actionOfEngineFactoryButton(){
    engineFactoryButton_->setColor( sf::Color::Green );
    factoryManager_.produceEngine();
    setActionMessege_( "Engine produced" );
}

void Interface::actionOfBatteryFactoryButton(){
    batteryFactoryButton_->setColor( sf::Color::Green );
    factoryManager_.produceBattery();
    setActionMessege_( "Battery produced" );
}

void Interface::mouseReleasedEvents_(){
    updateStateMessege_();
    resetColors_();
}

void Interface::resetColors_(){
    carFactoryButton_->setColor( sf::Color(255,255,255) ); /*WHITE*/
    frameFactoryButton_->setColor( sf::Color(255,255,255) );
    engineFactoryButton_->setColor( sf::Color(255,255,255) );
    batteryFactoryButton_->setColor( sf::Color(255,255,255) );
}

void Interface::updateStateMessege_(){
    std::string stateString = "Cars: " + std::to_string( factoryManager_.getCarNumber() ) +
                            "\nFrames: " + std::to_string( factoryManager_.getFrameNumber() ) +
                            "\nEngines: " + std::to_string ( factoryManager_.getEngineNumber() ) +
                            "\nBatteries: " + std::to_string ( factoryManager_.getBatteryNumber() );
    stateMessege_.setString( stateString );
}

void Interface::setActionMessege_( std::string newMessege){
    actionMessege_.setString( newMessege );
}
