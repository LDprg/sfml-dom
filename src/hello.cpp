#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::RectangleShape shape2({200, 300});
    shape2.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        static bool space = false;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Space)
                    space = !space;
        }


        window.clear();

        if (space)
            window.draw(shape);
        else
            window.draw(shape2);
        
        window.display();
    }

    return 0;
}