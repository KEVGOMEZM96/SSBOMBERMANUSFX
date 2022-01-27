#pragma once
#include "EnemyLoco.h"
class CartoonEnemyLoco :
    public EnemyLoco
{
public:
    CartoonEnemyLoco(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);
};

