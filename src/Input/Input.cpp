#include "Input.h"

void Input::Update() {
    GetKeyboardState(keyState);
}

bool Input::GetKeyState(int vkey) const {
    return (keyState[vkey] & 0x80) != 0;
}