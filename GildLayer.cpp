//
//  GildLayer.cpp
//  BeginnersGuide
//
//  Created by student on 15/9/29.
//
//

#include "GildLayer.h"
GildLayer *GildLayer::createLayer(Point p){
    GildLayer *ret = new (std::nothrow) GildLayer();
    if (ret && ret->init(p))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}
bool GildLayer:: init(Point p){
    Size s = Director::getInstance()->getWinSize();
    this->initWithColor(Color4B(0,0,0,200), s.width, s.height);
    
    auto sprite=Sprite::create("guide_finger.png");
    sprite->setPosition(p.x-600,p.y);
    this->addChild(sprite);
    auto move=MoveTo::create(1, p);
    auto call=CallFuncN::create([this,sprite,p](Node *){
        sprite->removeFromParent();
        ac=actionHand::create();
        ac->setPosition(p);
        this->addChild(ac);
            });
    setSwallowsTouches(true);
    auto sequence=Sequence::create(move,call, NULL);
    sprite->runAction(sequence);
    
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[this](Touch *touch, Event *unused_event){
        log("点击");
        return true;
    };
    listener->onTouchEnded=[this,p](Touch *touch, Event *unused_event){
        auto rect=Rect(p.x-30,p.y-30,50,50);
        if (rect.containsPoint(touch->getLocation())){
        this->removeFromParent();
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}