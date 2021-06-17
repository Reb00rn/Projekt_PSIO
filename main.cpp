#include <iostream>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include"plac_zabaw.h"
#include"collider.h"


int main()
{



    sf::RenderWindow window(sf::VideoMode(1200,800), "My window");


    //Załadowanie textury


    sf::Texture MinerTexture;
    MinerTexture.loadFromFile("miner1.png");


    Player player(&MinerTexture,sf::Vector2u(9,1),0.1f,100.0f);//(liczba animacji.x,y),czas delta

    float deltaTime = 0.0f;
    sf::Clock clock;




//window.setFramerateLimit(6);


    // run the program as long as the window is open
    while (window.isOpen())
    {
    deltaTime  = clock.restart().asSeconds();


 //EVENTS-------------------------------------------------------------
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
}

        // draw everything here...

        player.Update(deltaTime);
        window.clear(sf::Color(150,150,150));
        player.Draw(window);
        window.display();
        // end the current frame


}
    return 0;
}
