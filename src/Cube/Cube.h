#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <wrl/client.h>


class Cube {
public:
    Cube();
    bool Initialize(ID3D11Device* device);
    void Draw(ID3D11DeviceContext* deviceContext, const DirectX::XMMATRIX& wvpMatrix);

private:
    struct Vertex {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT4 color;
    };

    Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
    Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
    Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
    Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
    Microsoft::WRL::ComPtr<ID3D11Buffer> constantBuffer;
};
