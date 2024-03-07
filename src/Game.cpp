#include"Game.hpp"
#include <SFML/Graphics.hpp>
#include<iostream>

Game::Game()
:mWindow(sf::VideoMode(640, 480), "SFML Application")
, mPlayer()
, mStatisticsText()

{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);

    // mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
    mIsMovingUp = false;
    mIsMovingDown  = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;
}
/*
    This loop is most often called the main loop or the game loop because it 
    controls the lifetime of an application. As long as this one continues to iterate, the 
    application will stay alive.
    
    what do we do during an iteration of this loop? First we process the events 
    from the window, then we update the game, and finally we render the results on 
    the screen. 
*/
void Game::run()
{
    while(mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

/**
 * @brief The function processEvents() handles user input. It polls the application 
 * window for any input events, and will close the window if a Closed event occurs (the user 
 * clicks on the window's X button).
 * 
 */
void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if(key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if(key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if(key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if(key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}


/**
 * @brief The method update() updates the game logic, that is, everything that happens
 *  in the game. We are going to fill it as we add functionality to the game.   
 * 
 */
void Game::update()
{
    sf::Vector2f movement(0.f, 0.f);
    
    if (mIsMovingUp)
        movement.y -= 1.f;
    if (mIsMovingDown)
        movement.y += 1.f;
    if (mIsMovingLeft)
        movement.x -= 1.f;
    if (mIsMovingRight)
        movement.x += 1.f;
    
    mPlayer.move(movement);
}
/**
 * @brief The render() method renders our game to the screen. It consists of three parts. 
 * First, we clear the window with a color, usually black. Therefore, the output of the 
 * last rendering is completely overridden. Then, we draw all the objects of the current 
 * frame by calling the sf::RenderWindow::draw() method. After we have drawn 
 * everything, we need to actually display it on the screen.
 */
void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

// void Game::updateStatistics(sf::Time elapsedTime)
// {
// 	mStatisticsUpdateTime += elapsedTime;
// 	mStatisticsNumFrames += 1;

// 	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
// 	{
// 		mStatisticsText.setString(
// 			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
// 			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
							 
// 		mStatisticsUpdateTime -= sf::seconds(1.0f);
// 		mStatisticsNumFrames = 0;
// 	}
// }