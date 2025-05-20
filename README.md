# 🎮 Dodge the Cubes

A minimalist 3D action game built with **C++** and **DirectX 11**.  
You control a cube, dodging incoming red enemy cubes that fall from the sky.  
Built from scratch to learn low-level graphics, DirectX, and clean C++ game architecture.

---

## 🚀 Features

- 🧱 3D cube rendering with DirectX 11
- 🎮 Real-time input handling (WASD/Arrow keys)
- ⚙️ Fixed time-step game loop
- 🧠 Object-oriented architecture with `Player`, `Enemy`, `Entity`, and `Game` classes
- ✨ Expandable: Add textures, lighting, shaders, or sound later

---

## 🧠 Why This Exists

This project was built to address:
- My BOREDOM

---

## 🗂️ Project Structure

```

DodgeTheCubes/
├── src/
│   ├── main.cpp           # WinMain + message loop
│   ├── Renderer.\*         # DirectX 11 device/swap chain abstraction
│   ├── Game.\*             # Game logic, update & render
│   ├── Entity.\*           # Base entity class
│   ├── Player.\*           # Player logic
│   ├── Enemy.\*            # Enemy logic
│   └── Input.\*            # Keyboard input
├── Assets/                # Screenshots, textures (optional)
├── README.md
├── .gitignore
└── DodgeTheCubes.sln

````

---

## 🔧 Build Instructions (Windows)

### 🖥️ Requirements
- Visual Studio 2022 or newer
- Windows 10/11 SDK
- C++ Desktop Development Tools
- Linked libraries:
    - `d3d11.lib`
    - `dxgi.lib`
    - `d3dcompiler.lib`

### 🛠️ Steps

1. Clone the repo:
   ```bash
   git clone https://github.com/drowningFi5h/DodgeTheBlock.git

2. Open `DodgeTheCubes.sln` in Visual Studio
3. Build the solution (x64 Debug or Release)
4. Run the game!

---

## ✨ Possible Future Features

* Real-time shadows & lighting
* Collision detection
* Score tracking + UI
* Sound effects with XAudio2
* Shader effects (HLSL)
* 3D model loading (FBX/OBJ)

---

## 📸 Screenshots
Coming SOON!
