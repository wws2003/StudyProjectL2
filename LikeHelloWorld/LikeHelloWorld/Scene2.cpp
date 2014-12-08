//
//  Scene2.cpp
//  LikeHelloWorld
//
//  Created by wws2003 on 9/21/14.
//
//

#include "Scene2.h"

using namespace cocos2d;

bool Scene2::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    // add a "back" icon to return the previoud scene
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(Scene2::back));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width / 2, 30) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    // add "HelloWorld" splash screen"
    CCSprite* pSprite1 = CCSprite::create("HelloWorld.png");
    
    CCSize spriteSize = pSprite1->getContentSize();
    
    // position the sprite on the center of the screen
    pSprite1->setPosition( ccp(spriteSize.width / 2, size.height/2) );
    
    // add the sprite as a child to this layer
    this->addChild(pSprite1, 0);

    return true;
}

// there's no 'id' in cpp, so we recommend to return the class instance pointer
cocos2d::CCScene* Scene2::scene() {
    CCScene* scene = CCScene::create();
    
    Scene2* layer = Scene2::create();
    
    scene->addChild(layer);
    
    return scene;
}

void Scene2::back(CCObject* pSender) {
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->popScene();
}