#include "Player.hpp"
#include "TextureManager.hpp"

Player::Player(Properties* props)
    :Character(props)
{
    nRow     = 1;
    nFrame   = 10;
    animationSpeed = 60;
}
void    Player::Draw()
{
    TextureManager::GetInstance()->DrawFrame(ObjtextureID, Objtransform->GetX(), Objtransform->GetY(), Objwidth, Objheight, nRow, frame, Objflip);
}
void    Player::Updade(float dt)
{
    (void)dt;
    frame = (SDL_GetTicks() / animationSpeed) % nFrame;
}
void    Player::Clean()
{
    TextureManager::GetInstance()->clean();
}