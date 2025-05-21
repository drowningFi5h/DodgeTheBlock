#include "Cube/Cube.h"
#include <d3dcompiler.h>
#include <vector>
#include <wrl/client.h>

using namespace DirectX;
using Microsoft::WRL::ComPtr;

Cube::Cube() {
}

bool Cube::Initialize(ID3D11Device* device) {
    const Vertex vertices[] = {
        {{-0.5f, -0.5f, -0.5f}, {1, 0, 0, 1}}, // Red
        {{-0.5f, +0.5f, -0.5f}, {0, 1, 0, 1}}, // Green
        {{+0.5f, +0.5f, -0.5f}, {0, 0, 1, 1}}, // Blue
        {{+0.5f, -0.5f, -0.5f}, {1, 1, 0, 1}}, // Yellow
        {{-0.5f, -0.5f, +0.5f}, {1, 0, 1, 1}}, // Magenta
        {{-0.5f, +0.5f, +0.5f}, {0, 1, 1, 1}}, // Cyan
        {{+0.5f, +0.5f, +0.5f}, {1, 1, 1, 1}}, // White
        {{+0.5f, -0.5f, +0.5f}, {0, 0, 0, 1}}, // Black
    };

    const DWORD indices[] = {
        0, 1, 2, 0, 2, 3, // Front face
        4, 5, 6, 4, 6, 7, // Back face
        0, 1, 5, 0, 5, 4, // Left face
        2, 3, 7, 2, 7, 6, // Right face
        1, 2, 6, 1, 6, 5, // Top face
        0, 3, 7, 0, 7, 4  // Bottom face
    };

    // Vertex Buffer
    D3D11_BUFFER_DESC VbufferDesc = {};
    VbufferDesc.ByteWidth = sizeof(vertices);
    VbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    VbufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    VbufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices;

    if (const HRESULT hr = device->CreateBuffer(&VbufferDesc, &initData, vertexBuffer.GetAddressOf()); FAILED(hr)) return false;

    // Index Buffer
    D3D11_BUFFER_DESC IbufferDesc = {};
    IbufferDesc.ByteWidth = sizeof(indices);
    IbufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    IbufferDesc.Usage = D3D11_USAGE_DEFAULT;

    initData.pSysMem = indices;

    if (const HRESULT hr = device->CreateBuffer(&IbufferDesc, &initData, indexBuffer.GetAddressOf()); FAILED(hr)) return false;


    Microsoft::WRL::ComPtr<ID3DBlob> vsBlob;
    HRESULT hr = D3DCompileFromFile(
        L"src/Shader.hlsl", nullptr, nullptr, "VSMain", "vs_5_0",0 ,0, &vsBlob, nullptr);
    if (FAILED(hr)) {
        return false;
    }
    hr = device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, vertexShader.GetAddressOf());
    if (FAILED(hr)) {
        return false;
    }

    D3D11_INPUT_ELEMENT_DESC layout[] = {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    hr = device->CreateInputLayout(
        layout, ARRAYSIZE(layout),
        vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(),
        inputLayout.GetAddressOf());
    if (FAILED(hr)) {
        return false;
    }

    Microsoft::WRL::ComPtr<ID3DBlob> psBlob;
    hr = D3DCompileFromFile(
        L"src/Shader.hlsl", nullptr, nullptr, "PSMain", "ps_5_0", 0, 0, &psBlob, nullptr);
    if (FAILED(hr)) {
        return false;
    }
    hr = device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, pixelShader.GetAddressOf());
    if (FAILED(hr)) {
        return false;
    }

    D3D11_BUFFER_DESC cbd = {};
    cbd.Usage = D3D11_USAGE_DEFAULT;
    cbd.ByteWidth = sizeof(XMMATRIX);
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    hr = device->CreateBuffer(&cbd, nullptr, constantBuffer.GetAddressOf());
    if (FAILED(hr)) {
        return false;
    }
    return true;
}

void Cube::Draw(ID3D11DeviceContext *deviceContext, const XMMATRIX& wvpMatrix) {

    context->UpdateSubresource(
        constantBuffer.Get(),
        0,
        nullptr,
        &wvpMatrix,
        0, 0);
}
