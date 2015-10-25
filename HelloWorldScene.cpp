#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto sprite=Sprite::create("asimoxiaozhen.jpg");
    sprite->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(sprite);
    
    
    Node *node=Node::create();
    auto sp=Sprite::create("CloseSelected.png");
    sp->setScale(1.5);
    node->addChild(sp);
    
    auto lable1=Label::createWithSystemFont("点击", "", 30);
    lable1->setPosition(0,-30);
    node->addChild(lable1,3);
    node->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(node);

    
    
    
    auto layer=GildLayer::createLayer(Vec2(visibleSize.width/2, visibleSize.height/2));
    auto clip=ClippingNode::create();
    clip->setInverted(true);
    clip->setAlphaThreshold(0.0f);
    this->addChild(clip,10);
    clip->addChild(layer);   //底板
    clip->setStencil(node); //模板
    
    
    

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
}
