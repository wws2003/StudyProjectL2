#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Scene2.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width / 2, 30) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("What do you mean Poirot?", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite1 = CCSprite::create("HelloWorld.png");

    CCSize spriteSize = pSprite1->getContentSize();
    
    // position the sprite on the center of the screen
    pSprite1->setPosition( ccp(spriteSize.width / 2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite1, 0);
    
    // add the second "HelloWorld" splash screen"
    CCSprite* pSprite2 = CCSprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    pSprite2->setPosition( ccp(spriteSize.width + spriteSize.width / 2, size.height/2) );
    
    // add the sprite as a child to this layer
    this->addChild(pSprite2, 1);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->pushScene(Scene2::scene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
