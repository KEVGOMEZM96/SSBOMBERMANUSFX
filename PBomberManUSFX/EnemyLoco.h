#pragma once
//#include "Enemy.h"
#include "Entities/Enemy.h"
//#include <SDL.h>
//#include <memory>
//#include <utility>
//#include <vector>
//#include <iostream>
//#include <fstream>
//#include <string>
//
//#include "../Const.h"
//#include "../Entities/Music.h"
//#include "../Entities/Sound.h"
//#include "../Entities/Text.h"
//#include "../Scenes/Scene.h"
//#include "../GameManager.h"
//#include "../Managers/AssetManager.h"
//#include "../GameAITypes.h"
//#include "../GameTextures.h"
class EnemyLoco : public Enemy
{
public:
	EnemyLoco(std::shared_ptr<SDL_Texture> texture, SDL_Renderer* renderer);

};

