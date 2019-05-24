#ifndef _GUI_H_
#define _GUI_H_

#include "factory_manager.h"
#include "button.h"

class Interface{
public:
    void mainLoop();
    Interface();
    ~Interface();
private:
    sf::RenderWindow* window_;
    sf::Font font_;

    FactoryManager factoryManager_;

    Button* carFactoryButton_;
    Button* frameFactoryButton_;
    Button* engineFactoryButton_;
    Button* batteryFactoryButton_;

    sf::Text stateMessege_;
    sf::Text actionMessege_;

    void drawButtons_();
    /* draws stateMessege_ and actionMessege_ */
    void drawTexts_();
    /* attaches textures and locates buttons */
    void setButtons_();
    /* calls all MousePressed events*/
    void mousePressedEvents_();
    /* chooses specyfic function  */
    void checkButtons_();
    /* calls all MouseReleased enevts*/
    void mouseReleasedEvents_();
    /* resets all buttons fill color to black*/
    void resetColors_();
    /* updates stateMessege_ */
    void updateStateMessege_();

    void setActionMessege_( std::string newMessege );

    void actionOfCarFactoryButton();
    void actionOfFrameFactoryButton();
    void actionOfEngineFactoryButton();
    void actionOfBatteryFactoryButton();


};


#endif
