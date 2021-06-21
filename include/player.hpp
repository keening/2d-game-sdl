#include "../include/sprite.hpp"

enum PlayerDirection { UP, DOWN, LEFT, RIGHT };

class Player : Sprite {
    public:
        Player();
        Player(Display &display, Sprite &sprite, i32 x, i32 y, i32 w, i32 h);
        ~Player();

        void draw(Display &display, Sprite &sprite);
        void move(PlayerDirection direction);

    private:
        i32 m_x, m_y, m_w, m_h, m_speed = 10;
};