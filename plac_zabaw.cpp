#include "plac_zabaw.h"


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


Animation::Animation(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_)
{
    this->image_count_ = image_count_;
    this->switchTime_ = switchTime_;
    totalTime_ = 0.0;
    current_image_.x = 0.0;


    uvRect.width = texture->getSize().x/float(image_count_.x);//szerokość tekstury
    uvRect.height = texture->getSize().y/float(image_count_.y);//wysokość tekstury
}
Animation::~Animation()
{

}

void Animation::Update(int row,float deltaTime,bool FaceRight)
{
    current_image_.y = row;
    totalTime_+= deltaTime;

    if(totalTime_>= switchTime_)//płynniejszy ruch animacji
    {
        totalTime_ -=switchTime_;
        current_image_.x++;

        if(current_image_.x>=image_count_.x)// w razie gdy rząd się kończy przechodzi do kolejnego
        {
            current_image_.x = 0;
        }

    }

    uvRect.top = current_image_.y * uvRect.height;

    if(FaceRight)
    {
            uvRect.left = current_image_.x * uvRect.width;
            uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (current_image_.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

//Player-------------------------------------------------------------------------------------------------------------------------------------------------------

Player::Player(sf::Texture*texture, sf::Vector2u image_count_,float switchTime_,float speed_):animation_(texture, image_count_,switchTime_)
{
 this-> speed_ = speed_;
    row_ = 0;
    FaceRight_ = true;

        body_.setSize(sf::Vector2f(50,100.0));
        body_.setPosition(500,400);
        body_.setTexture(texture);
}
Player::~Player()
{

}
void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed_*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed_*deltaTime;
    }

    if(movement.x == 0.0f)
    {
        row_ =0;
        deltaTime = 0;
    }
    else
    {
        row_ = 0;

        if(movement.x>0.0f)
        {
            FaceRight_ = true;
        }
        else
        {
            FaceRight_ = false;
        }
    }
    animation_.Update(row_,deltaTime,FaceRight_);
    body_.setTextureRect(animation_.uvRect);
    body_.move(movement);

}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body_);
}

