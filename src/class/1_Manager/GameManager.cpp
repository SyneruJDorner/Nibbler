# include "GameManager.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//GameManager::instance->WHAT_YOU_WANT();
GameManager *GameManager::instance = new GameManager();

GameManager::GameManager()
{
    this->renderEngine = NULL;
}

GameManager::GameManager(std::string libsDir[], int width, int height)
{
    SetupManagerForInstance(libsDir, width, height);
}

GameManager::GameManager(GameManager &obj)
{
    RenderEngine *engine = new RenderEngine(
        obj.renderEngine->getLibDirectories(),
        obj.renderEngine->getWidth(),
        obj.renderEngine->getHeight(),
        obj.renderEngine->GetGridSize(),
        obj.renderEngine->getActiveLibNum()
    );

    this->renderEngine = engine;
}

GameManager::~GameManager()
{
    delete this->renderEngine;
    delete this->world;
}

GameManager &GameManager::operator=(GameManager const &other)
{
    RenderEngine *engine = new RenderEngine(
            other.renderEngine->getLibDirectories(),
            other.renderEngine->getWidth(),
            other.renderEngine->getHeight(),
            other.renderEngine->GetGridSize(),
            other.renderEngine->getActiveLibNum()
        );

    this->renderEngine = engine;
    return *this;
}

void GameManager::SetupManagerForInstance(std::string libsDir[], int width, int height)
{
    this->timeScale = 66;
    this->bonusFoodCnt = 1;
    this->bonusSpawnAmt = 2;
    this->cellSize = 10;
    this->world = new World(width, height, this->cellSize);
    this->renderEngine = new RenderEngine(libsDir, width, height, this->cellSize, 1);
    Player::instance->SetupSnake(width/10, height/10);

    //Setup Surrounding Wall
    for (int y = 0; y < height/this->cellSize; y++)
    {
        for (int x = 0; x < width/this->cellSize; x++)
        {
            if ((y == 1 && (x > 1 && x < (width - this->cellSize)/this->cellSize)) || x == 1 || x == (width - this->cellSize)/this->cellSize)
            {
                Obsticle temp;
                temp.trans.Position.x = x;
                temp.trans.Position.y = y;
                temp.type = Collidable;
                temp.trans.Color.SetColour(0.5, 0.5, 0.5, 1);
                ObsticleCollection::instance->getObsticleList()->push_back(temp);
            }
            if ((y == (height-cellSize)/this->cellSize && (x > 1 && x < (width - this->cellSize)/this->cellSize)) || x == 1 || x == (width  - this->cellSize)/this->cellSize)
            {
                Obsticle temp;
                temp.trans.Position.x = x;
                temp.trans.Position.y = y;
                temp.type = Collidable;
                temp.trans.Color.SetColour(0.5, 0.5, 0.5, 1);
                ObsticleCollection::instance->getObsticleList()->push_back(temp);
            }
        }
    }

    //Spawn Collectable
    Obsticle temp;
    temp.trans.Position.x = rand() % (width - 2 * cellSize)/cellSize + 2;
    temp.trans.Position.y = rand() % (height - 2 * cellSize)/cellSize + 2;
    temp.type = Collectable;
    temp.trans.Color.SetColour(0.0, 1.0, 0.2, 1);
    ObsticleCollection::instance->getCollectablesList()->push_back(temp);
}

RenderEngine *GameManager::getRenderEngine()
{
    return this->renderEngine;
}

World *GameManager::GetWorld()
{
    return this->world;
}

void GameManager::passPlayer(KeyCode keycode)
{
    //Queue everything for rendering
    Player::instance->PlayerMovement(keycode);
    SnakeBody *snakeBody = Player::instance->getSnake();
    std::vector<Obsticle> *borderWall = ObsticleCollection::instance->getObsticleList();
    std::vector<Obsticle> *collectables = ObsticleCollection::instance->getCollectablesList();
    std::vector<Obsticle> *bonusCollectables = ObsticleCollection::instance->getBonusCollectablesList();

    //Queueing head
    Grid_t PlayerHead = Grid_t();
    PlayerHead.position = snakeBody->Head.Position;
    PlayerHead.color = snakeBody->Head.Color;
    getRenderEngine()->getGraphicLib()->draw(PlayerHead);

    //Queueing body
    for (size_t i = 0; i < snakeBody->Body.size(); i++)
    {
        Grid_t PlayerBody = Grid_t();
        PlayerBody.position = snakeBody->Body[i].Position;
        
        //Easter egg rainbow
        if (rainbowMode == true)
            snakeBody->Body[i].Color.SetColour((double)randomRange(0, 255)/255, (double)randomRange(0, 255)/255, (double)randomRange(0, 255)/255, 1.0);

        PlayerBody.color = snakeBody->Body[i].Color;
        getRenderEngine()->getGraphicLib()->draw(PlayerBody);  
    }
    
    //Queueing Border Wall
    for (auto i = borderWall->begin(); i != borderWall->end(); ++i)
    {
        Grid_t wallBlock = Grid_t();
        wallBlock.position = i->trans.Position;
        wallBlock.color = i->trans.Color;
        getRenderEngine()->getGraphicLib()->draw(wallBlock);
    }

    //Queueing Collectables
    for (auto i = collectables->begin(); i != collectables->end(); ++i)
    {
        Grid_t pickup = Grid_t();
        pickup.position = i->trans.Position;
        pickup.color = i->trans.Color;
        getRenderEngine()->getGraphicLib()->draw(pickup);
    }

    //Queueing Bonus Collectables
    for (auto i = bonusCollectables->begin(); i != bonusCollectables->end(); ++i)
    {
        Grid_t pickup = Grid_t();
        pickup.position = i->trans.Position;
        pickup.color = i->trans.Color;
        getRenderEngine()->getGraphicLib()->draw(pickup);
    }

    //Finally render everything we queued
    getRenderEngine()->getGraphicLib()->updateDisplay();
}

bool GameManager::Collisions()
{
    SnakeBody *snakeBody = Player::instance->getSnake();
    std::vector<Obsticle> *borderWall = ObsticleCollection::instance->getObsticleList();
    std::vector<Obsticle> *collectables = ObsticleCollection::instance->getCollectablesList();
    std::vector<Obsticle> *bonusCollectables = ObsticleCollection::instance->getBonusCollectablesList();

    //Collision with Collectable
    for (auto i = collectables->begin(); i != collectables->end() ; ++i)
    {
        if (snakeBody->Head.Position.x == i->trans.Position.x)
            if (snakeBody->Head.Position.y == i->trans.Position.y)
            {
                if (i->type == Collectable)
                {
                    ObsticleCollection::instance->getCollectablesList()->erase(i);
                    GeneralFood();

                    if (this->bonusFoodCnt++ == bonusSpawnAmt)//Happens every 4 food pickups
                    {
                        BonusFood();
                    }
                }

                //Grow Snake body
                Transform_t bodyPart;
                bodyPart.Position.x = snakeBody->Body[snakeBody->Body.size() - 1].Position.x;
                bodyPart.Position.y = snakeBody->Body[snakeBody->Body.size() - 1].Position.y; 
                bodyPart.Direction = DIR_NUL;
                bodyPart.Color.SetColour(1, 0, 0, 1.0);
                
                Player::instance->UpdateSnakeBody();
                Player::instance->getSnake()->Body.push_back(bodyPart);
                IncrementTimeScale(4);

                return false;
            }
    }

    for (auto i = bonusCollectables->begin(); i != bonusCollectables->end() ; ++i)
    {
        if (i->lifespan > 0)
        {
            i->lifespan -= (double)GameManager::instance->GetTimeScale() / 1000;
        }
        else
        {               
            this->bonusFoodCnt = 0;
            ObsticleCollection::instance->getBonusCollectablesList()->erase(i);
            break;
        }

        if (snakeBody->Head.Position.x == i->trans.Position.x)
            if (snakeBody->Head.Position.y == i->trans.Position.y)
            {
                if (i->type == BonusCollectable)
                {
                    this->bonusFoodCnt = 0;
                    ObsticleCollection::instance->getBonusCollectablesList()->erase(i);
                }

                //Grow Snake body
                Transform_t bodyPart;
                bodyPart.Position.x = snakeBody->Body[snakeBody->Body.size() - 1].Position.x;
                bodyPart.Position.y = snakeBody->Body[snakeBody->Body.size() - 1].Position.y; 
                bodyPart.Direction = DIR_NUL;
                bodyPart.Color.SetColour(1.0, 0.0, 0.0, 1.0);
                Player::instance->UpdateSnakeBody();
                Player::instance->getSnake()->Body.push_back(bodyPart);
                IncrementTimeScale(4);

                return false;
            }
    }

    //Collision with Body
    for (size_t i = 0; i < snakeBody->Body.size(); i++)
    {
        if (snakeBody->Head.Position.x == snakeBody->Body[i].Position.x)
            if (snakeBody->Head.Position.y == snakeBody->Body[i].Position.y)
                return true;
    }

    //Collision with Wall
    for (auto i = borderWall->begin(); i != borderWall->end(); ++i)
    {
        if (snakeBody->Head.Position.x == i->trans.Position.x)
            if (snakeBody->Head.Position.y == i->trans.Position.y)
                return true;

        for (size_t x = 0; x < snakeBody->Body.size(); x++)
        {
            if (snakeBody->Body[x].Position.x == i->trans.Position.x)
                if (snakeBody->Body[x].Position.y == i->trans.Position.y)
                    return true;
        }
    }

    return false;
}

void GameManager::GeneralFood()
{
    Obsticle temp;
    //temp.trans.Position.x = rand() % ((GetWorld()->getWidth() - (2 * this->cellSize))/this->cellSize) + 2;
    //temp.trans.Position.y = rand() % ((GetWorld()->getHeight() - (2 * this->cellSize))/this->cellSize) + 2;
    
    int minX = 2;
    int maxX = (GetWorld()->getWidth() - (2 * this->cellSize))/this->cellSize;
    temp.trans.Position.x = randomRange(minX, maxX);// % ((GetWorld()->getWidth() - (2 * this->cellSize))/this->cellSize) + 2;
    
    int minY = 2;
    int maxY = (GetWorld()->getHeight() - (2 * this->cellSize))/this->cellSize;
    temp.trans.Position.y = randomRange(minY, maxY);//% ((GetWorld()->getHeight() - (2 * this->cellSize))/this->cellSize) + 2;

    temp.type = Collectable;
    temp.trans.Color.SetColour(0.0, 1.0, 0.2, 1);
    ObsticleCollection::instance->getCollectablesList()->push_back(temp);
}

void GameManager::BonusFood()
{
    Obsticle temp;

    int minX = 2;
    int maxX = (GetWorld()->getWidth() - (2 * this->cellSize))/this->cellSize;
    temp.trans.Position.x = randomRange(minX, maxX);// % ((GetWorld()->getWidth() - (2 * this->cellSize))/this->cellSize) + 2;
    
    int minY = 2;
    int maxY = (GetWorld()->getHeight() - (2 * this->cellSize))/this->cellSize;
    temp.trans.Position.y = randomRange(minY, maxY);//% ((GetWorld()->getHeight() - (2 * this->cellSize))/this->cellSize) + 2;
    
    temp.type = BonusCollectable;
    temp.trans.Color.SetColour(0.0, 0.0, 1.0, 1);
    temp.lifespan = 5;
    ObsticleCollection::instance->getBonusCollectablesList()->push_back(temp);
}

int GameManager::randomRange(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

int GameManager::GetTimeScale()
{
    return (this->timeScale);
}

void GameManager::IncrementTimeScale(int amt)
{
    this->timeScale -= amt;
    this->timeScale = (this->timeScale < 12) ? 12 : this->timeScale;
}

void GameManager::EnableRainbowMode()
{
    this->rainbowMode = true;
}