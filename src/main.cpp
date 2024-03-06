 #include <SFML/Graphics.hpp>
 #include"Engine.hpp"
 #include<iostream>
 
int main()
{
    Engine myEngine = Engine();
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFMLApplication");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
}