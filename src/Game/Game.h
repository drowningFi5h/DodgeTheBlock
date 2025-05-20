#pragma once
#include "../Renderer/Renderer.h"
#include "../Input/Input.h"
#include "../Player/Player.h"

class Game {
public:
    Game(Renderer* renderer);

    void Update();
    void Render();
private:
    Player player;
    Input input;
    Renderer* renderer;
};