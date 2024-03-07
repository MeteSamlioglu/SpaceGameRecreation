#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        void run();
        
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
    
    private:
        void processEvents();
        void update();
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    private:
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
        sf::Text mStatisticsText;
      
};

#endif