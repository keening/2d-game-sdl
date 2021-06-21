#include "../include/sprite.hpp"

enum PlayerDirection { UP, DOWN, LEFT, RIGHT };

class Player : Sprite {
    public:
        Player();
        Player(Display &display, Sprite &sprite, i32 x, i32 y, i32 w, i32 h);
        ~Player();

        i32 get_x(); i32 get_y();
        i32 get_w(); i32 get_h();
        void draw(Display &display, Sprite &sprite);
        void move(PlayerDirection direction, i32 distance);

    private:
        i32 m_x, m_y, m_w, m_h, m_speed;
};