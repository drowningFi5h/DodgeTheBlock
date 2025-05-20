#include "Game.h"

Game::Game(Renderer *renderer): renderer(renderer) {

}

void Game::Update() {
    input.Update();
    player.Update(input);
}

void Game::Render() {
    player.Render(*renderer);
}
