#pragma once
#include "../Input/Input.h"
#include "../Renderer/Renderer.h"
#include <DirectXMath.h>
class Player
{
public:
    Player();

    void Update( const Input& input);
    void Render( Renderer& renderer);

private:
    DirectX::XMFLOAT3 position;
};