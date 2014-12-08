//
//  Scene2.h
//  LikeHelloWorld
//
//  Created by wws2003 on 9/21/14.
//
//

#ifndef __LikeHelloWorld__Scene2__
#define __LikeHelloWorld__Scene2__

#include "cocos2d.h"

class Scene2 : public cocos2d::CCLayer {
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
   
    void back(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Scene2);
};

#endif /* defined(__LikeHelloWorld__Scene2__) */
