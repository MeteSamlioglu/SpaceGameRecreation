#include <SFML/Graphics.hpp>
#ifndef Engine_hpp
#define Engine_hpp
class Engine
{
    public:
        Engine();
        void run();
    
    private:
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
};

#endif