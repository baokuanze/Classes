//
//  GildLayer.h
//  BeginnersGuide
//
//  Created by student on 15/9/29.
//
//

#ifndef __BeginnersGuide__GildLayer__
#define __BeginnersGuide__GildLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "actionHand.h"
USING_NS_CC;
class GildLayer:public LayerColor{
public:
    
    static GildLayer *createLayer(Point p);
    virtual bool init(Point p);
    actionHand *ac;
};

#endif /* defined(__BeginnersGuide__GildLayer__) */
