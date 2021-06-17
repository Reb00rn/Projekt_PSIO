#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_);
    ~Animation();
    void Update(int row,float deltaTime, bool FaceRight);
public:
    sf::IntRect uvRect;

private:
    sf::Vector2u image_count_;
    sf::Vector2u current_image_;

    float totalTime_;
    float switchTime_;
};

class Player
{
public:
    Player(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_,float speed_);
   ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);//not needed

private:
    sf::RectangleShape body_;
    Animation animation_;
    unsigned int row_;
    float speed_;
    bool FaceRight_;
};



