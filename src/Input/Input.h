#pragma once
#include <windows.h>

class Input {
public:
    void Update();
    bool GetKeyState(int vkey) const;

private:
    BYTE keyState[256]{};
};