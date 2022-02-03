#include <string>

#include "../Entities/Sprite.h"
#include "../GameManager.h"
#include "../Scenes/GameOverScene.h"
#include "../Scenes/LevelScene.h"
#include "../Scenes/MenuScene.h"
#include "../Scenes/StageScene.h"

// ++increment for menu id
MenuItem& operator++(MenuItem& c)
{
    using type = typename std::underlying_type<MenuItem>::type;
    c = static_cast<MenuItem>(static_cast<type>(c) + 1);
    if(c == MenuItem::Last)
        c = static_cast<MenuItem>(static_cast<type>(MenuItem::None) + 1);
    return c;
}

// --decrement for menu id
MenuItem& operator--(MenuItem& c)
{
    using type = typename std::underlying_type<MenuItem>::type;
    c = static_cast<MenuItem>(static_cast<type>(c) - 1);
    if(c == MenuItem::None)
        c = static_cast<MenuItem>(static_cast<type>(MenuItem::Last) - 1);
    return c;
}

// increment++ for menu id
MenuItem operator++(MenuItem& c, int)
{
    MenuItem result = c;
    ++c;
    return result;
}

// decrement-- for menu id
MenuItem operator--(MenuItem& c, int)
{
    MenuItem result = c;
    --c;
    return result;
}

MenuScene::MenuScene(GameManager* _gameManager) : Scene(_gameManager)
{
    // background
    auto background = std::make_shared<Sprite>(gameManager->getAssetManager()->getTexture(GameTexture::MenuBack), gameManager->getRenderer());
    
    background->setPosition(30, 20);
    
    background->setSize(gameManager->getWindowWidth() - 60,  static_cast<int>(gameManager->getWindowHeight() / 1.5f) - 20);
    addObject(background);

    // start menu
   /* startText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "INICIO");
    startText->setColor(colorPressed);
    startText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    startText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - startText->getWidth() / 2.0f), background->getHeight() + 60);
    addObject(startText);*/

    Player1starText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "1 PLAYER");
    Player1starText->setColor(colorPressed);
    Player1starText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    Player1starText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - Player1starText->getWidth() / 2.0f), background->getHeight() + 20);
    addObject(Player1starText);

    Player2starText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "2 PLAYER");
    Player2starText->setColor(colorStandard);
    Player2starText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    Player2starText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - Player1starText->getWidth() / 2.0f), background->getHeight() + 50);
    addObject(Player2starText);

    Player3starText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "3 PLAYER");
    Player3starText->setColor(colorStandard);
    Player3starText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    Player3starText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - Player2starText->getWidth() / 2.0f), background->getHeight() + 80);
    addObject(Player3starText);

    Player4starText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "4 PLAYER");
    Player4starText->setColor(colorStandard);
    Player4starText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    Player4starText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - Player3starText->getWidth() / 2.0f), background->getHeight() + 110);
    addObject(Player4starText);



    /*startCartoonText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "CARTOON");
    startCartoonText->setColor(colorPressed);
    startCartoonText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    startCartoonText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - startCartoonText->getWidth() / 2.0f), background->getHeight() + 20);
    addObject(startCartoonText);

    startClasicText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "CLASICO");
    startClasicText->setColor(colorStandard);
    startClasicText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    startClasicText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - startCartoonText->getWidth() / 2.0f), background->getHeight() + 50);
    addObject(startClasicText);
   
    startCustomText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "CUSTOM");
    startCustomText->setColor(colorStandard);
    startCustomText->setSize(static_cast<int>(gameManager->getWindowWidth() / 4.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    startCustomText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - startClasicText->getWidth() / 2.0f), background->getHeight() + 80);
    addObject(startCustomText);

    startRealisticText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "REAL");
    startRealisticText->setColor(colorStandard);
    startRealisticText->setSize(static_cast<int>(gameManager->getWindowWidth() / 7.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    startRealisticText->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - startCustomText->getWidth() / 2.0f), background->getHeight() + 110);
    addObject(startRealisticText);*/

    // exit menu
    exitText = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(), "SALIR");
    exitText->setSize(static_cast<int>(gameManager->getWindowWidth() / 5.0f), static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    exitText->setPosition(Player1starText->getPositionX(), Player4starText->getPositionY() + exitText->getHeight() + 40);
    addObject(exitText);

    gameManager->getSceneManager()->addScene("gameover", std::make_shared<GameOverScene>(gameManager));
    // menu music
    menuMusic = std::make_shared<Music>(gameManager->getAssetManager()->getMusic(MusicEnum::MainMenu));
}

void MenuScene::onEnter()
{
    menuMusic->play();
}

void MenuScene::onExit()
{
    menuMusic->stop();
}

void MenuScene::onEvent(const SDL_Event& event)
{
    Scene::onEvent(event);
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.scancode)
        {
            // we should select next menu item
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                currentSelectedMenu++;
                onMenuItemSelect();
                break;
            // we should select prev menu item
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                currentSelectedMenu--;
                onMenuItemSelect();
                break;
            // enter in menu item
            case SDL_SCANCODE_SPACE:
            case SDL_SCANCODE_RETURN:
                onMenuItemPress();
                break;
            default:
                break;
        }
    }
}

void MenuScene::onMenuItemSelect()
{
    // reset menu items color
    //startCartoonText->setColor(colorStandard);
    //startClasicText->setColor(colorStandard);
    //startCustomText->setColor(colorStandard);
    //startRealisticText->setColor(colorStandard);





    Player1starText->setColor(colorStandard);
    Player2starText->setColor(colorStandard);
    Player3starText->setColor(colorStandard);
    Player4starText->setColor(colorStandard);
    exitText->setColor(colorStandard);
    // change color of selected menu item
    switch(currentSelectedMenu)
    {
    case MenuItem::Start1Player:
        Player1starText->setColor(colorPressed);
        break;
    case MenuItem::Start2Player:
        Player2starText->setColor(colorPressed);
        break;
    case MenuItem::Start3Player:
        Player3starText->setColor(colorPressed);
        break;
    case MenuItem::Start4Player:
        Player4starText->setColor(colorPressed);
        break;
    case MenuItem::Exit:
        exitText->setColor(colorPressed);
        break;
    default:
        break;
         
    }
}

void MenuScene::onMenuItemPress()
{
    switch(currentSelectedMenu)
    {
        //case MenuItem::StartCartoon:
        //    // go to level scene
        //    gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CARTOON, 1, 0));
        //    gameManager->getSceneManager()->activateScene("stage");
        //    break;
        //case MenuItem::StartClasic:
        //    // go to level scene
        //    gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CLASIC, 1, 0));
        //    gameManager->getSceneManager()->activateScene("stage");
        //    break;
        //case MenuItem::StartCustom:
        //    // go to level scene
        //    gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CUSTOM, 1, 0));
        //    gameManager->getSceneManager()->activateScene("stage");
        //    break;
        //case MenuItem::StartRealistic:
        //    // go to level scene
        //    gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_REALISTIC, 1, 0));
        //    gameManager->getSceneManager()->activateScene("stage");
        //    break;
        //case MenuItem::Exit:
        //    // stop gameManager loop
        //    gameManager->stop();
        //    break;
    case MenuItem::Start1Player:
        // go to level scene
        gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CARTOON, Players::PLAYER_1, 1, 0));
        gameManager->getSceneManager()->activateScene("stage");
        break;
    case MenuItem::Start2Player:
        // go to level scene
        gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CARTOON, Players::PLAYER_2, 1, 0));
        gameManager->getSceneManager()->activateScene("stage");
        break;
    case MenuItem::Start3Player:
        // go to level scene
        gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CARTOON, Players::PLAYER_3, 1, 0));
        gameManager->getSceneManager()->activateScene("stage");
        break;
    case MenuItem::Start4Player:
        // go to level scene
        gameManager->getSceneManager()->addScene("stage", std::make_shared<StageScene>(gameManager, GameVersion::GAMEVERSION_CARTOON, Players::PLAYER_4, 1, 0));
        gameManager->getSceneManager()->activateScene("stage");
        break;
    case MenuItem::Exit:
        // stop gameManager loop
        gameManager->stop();
        break;
        default:
            break;
    }
}
