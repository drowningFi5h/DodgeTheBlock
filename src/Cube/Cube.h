#pragma once
#include <d3d11.h>
#include <DirectXMath.h>



class Cube {
public:
    Cube();
    bool Initialize(ID3D11Device* device);
    void Draw(ID3D11DeviceContext* deviceContext, const DirectX::XMMATRIX& wvpMatrix);

};
