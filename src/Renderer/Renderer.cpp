#include <ratio>
#include <d3d11.h>
#include "Renderer.h"



Renderer::Renderer() {}
Renderer::~Renderer(){}

bool Renderer::Initialize(HWND hwnd, int width, int height) {
    if (!CreateDeviceAndSwapChain(hwnd, width, height)) {
        return false;
    }
    CreateRenderTarget();
    return true;
}

bool Renderer::CreateDeviceAndSwapChain(HWND hwnd, int width, int height) {
    DXGI_SWAP_CHAIN_DESC scDesc = {};
    scDesc.BufferCount = 1;
    scDesc.BufferDesc.Width = width;
    scDesc.BufferDesc.Height = height;
    scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scDesc.OutputWindow = hwnd;
    scDesc.SampleDesc.Count = 1;
    scDesc.Windowed = TRUE;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
        nullptr, 0, D3D11_SDK_VERSION, &scDesc,
        swapChain.GetAddressOf(), device.GetAddressOf(), nullptr, deviceContext.GetAddressOf()
        );
    return SUCCEEDED(hr);
}

void Renderer::CreateRenderTarget() {
    Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, renderTargetView.GetAddressOf());
    deviceContext->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), nullptr);
}
void Renderer::Clear(float r, float g, float b, float a) {
    float clearColor[] = {r, g, b, a};
    deviceContext->ClearRenderTargetView(renderTargetView.Get(), clearColor);
}
void Renderer::Present() {
    swapChain->Present(1, 0);
}
