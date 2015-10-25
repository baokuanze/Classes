//
//  actionHand.h
//  BeginnersGuide
//
//  Created by student on 15/9/30.
//
//

#ifndef __BeginnersGuide__actionHand__
#define __BeginnersGuide__actionHand__

#include <stdio.h>
#include "cocos2d.h"
#include <iostream>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace std;
using namespace cocostudio;
USING_NS_CC;
class  actionHand:public Armature{
public:
    actionHand(){};
    static actionHand *create();
    virtual bool init();
   // CREATE_FUNC(actionHand);


};


#endif /* defined(__BeginnersGuide__actionHand__) */
