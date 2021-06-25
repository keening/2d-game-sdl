#include "../include/player.hpp"
#include "../include/display.hpp"

Player::Player() {}

Player::Player(Display &display, i32 x, i32 y) : 
        Sprite(display, "./assets/tileset.png", 32, 32, x, y),
        m_x(x), m_y(y), m_w(SPRITE_SIZE), m_h(SPRITE_SIZE) 
{
}

Player::~Player() {}

void Player::draw(Display &display)
{
    set_sprite(display);
    Sprite::draw(display, m_x, m_y);
}

void Player::move(Direction dir)
{
    switch (dir)
    {
        case LEFT:
            m_x -= m_speed;
            break;
        case RIGHT:
            m_x += m_speed; 
            break;
        case UP:
            m_y -= m_speed; 
            break;
        case DOWN:
            m_y += m_speed;
            break;
        default:
            break;
    }
}

void Player::set_sprite(Display &display)
{
    Sprite::set_rect(Sprite::read_sprite_from_file("./assets/player.dat", "default"));
}