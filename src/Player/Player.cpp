#include "Player.h"

using namespace DirectX;

Player::Player() : position(0.0f, 0.0f, 0.0f) {}

void Player::Update(const Input& input) {
    float speed = 0.1f;

    if (input.GetKeyState('W')) position.y += speed;
    if (input.GetKeyState('S')) position.y -= speed;
    if (input.GetKeyState('A')) position.x -= speed;
    if (input.GetKeyState('D')) position.x += speed;

    //Player position clamping
}

void Player::Render(Renderer &renderer) {

}
