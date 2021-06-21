#include "../include/player.hpp"

// Player constructor for atlas based sprite
Player::Player(Display &display, Sprite &sprite, i32 x, i32 y, i32 w, i32 h) :
    m_x (x), m_y (y), m_w (w), m_h (h)
{
    //clip_from_atlas(sprite, x, y, w, h);
    //sprite.draw(display, x, y, w, h);
}

Player::~Player() {}

void Player::draw(Display &display, Sprite &sprite)
{
    // PLAYER ATLAS POSITION AT 120, 100.
    sprite.draw_from_atlas(display, m_x, m_y, m_w, m_h, 120, 110);
}

void Player::move(PlayerDirection direction)
{
    i32 new_position, current_position;

    switch(direction)
    {
        case UP:
            current_position = m_y;
            new_position = current_position - m_speed;
            m_y = new_position;
            break;

        case DOWN:
            current_position = m_y;
            new_position = current_position + m_speed;
            m_y = new_position;
            break;

        case LEFT:
            current_position = m_x;
            new_position = current_position - m_speed;
            m_x = new_position;
            break;

        case RIGHT:
            current_position = m_x;
            new_position = current_position + m_speed;
            m_x = new_position;
            break;

        default:
            break;
    }
}