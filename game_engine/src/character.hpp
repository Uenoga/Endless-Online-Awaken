// Endless Online Awaken

#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include "const/entity.hpp"
#include "animation.hpp"

#include <string>
#include <memory>

class Character
{
public:
    enum class AnimState
    {
        Stand,
        Sit,
        Walk,
        Attack
    };

    enum class Action
    {
        Face,
        Walk
    };

public:
    std::string name;
    unsigned int map_id;
    unsigned short x;
    unsigned short y;
    Direction direction;
    Gender gender;
    unsigned char speed;

    AnimState anim_state;
    Animation animation;

    int screen_x;
    int screen_y;

    int frame_counter;

    Character();
    Character(std::string name, unsigned int map_id, unsigned short x, unsigned short y);

    void Tick();
    void Render(int rx, int ry);
    void RenderNew(int rx, int ry);

    std::vector<int> GetScreenPos();

    void Talk(unsigned char channel, std::string message, std::string char_name = "");
    void Face(Direction direction);
    void Walk(Direction direction);
};

#endif // CHARACTER_HPP_INCLUDED
