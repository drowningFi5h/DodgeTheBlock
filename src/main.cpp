#include<windows.h>
#include "Renderer/Renderer.h"
#include "Game/Game.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    constexpr int width = 800, height = 600;

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "DodgeTheCubes";
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
    0, wc.lpszClassName, "DodgeTheCubes", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, width, height,
    nullptr, nullptr, hInstance,nullptr
    );
    ShowWindow(hwnd, nCmdShow);

    Renderer renderer;

    Game game(&renderer);

    if (!renderer.Initialize(hwnd, width, height)) {
        MessageBox(hwnd, "Failed to initialize renderer", "Error", MB_OK);
        return -1;
    }

    MSG msg = {};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }else {
            game.Update();
            renderer.Clear(0.2f, 0.6f, 1.0f, 1.0f);
            game.Render();
            renderer.Present();
        }
    }
    return 0;
}
