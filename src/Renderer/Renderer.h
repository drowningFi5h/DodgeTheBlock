#pragma once
#include<wrl/client.h>
#include <d3d11.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool Initialize(HWND hwnd, int width, int height);
    void Clear(float r, float g, float b, float a);
    void Present();

private:
    Microsoft::WRL::ComPtr<ID3D11Device> device;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

    bool CreateDeviceAndSwapChain(HWND hwnd, int width, int height);
    void CreateRenderTarget();
};