//
//  actionHand.cpp
//  BeginnersGuide
//
//  Created by student on 15/9/30.
//
//

#include "actionHand.h"
actionHand *actionHand:: create(){
    actionHand *handle = new (std::nothrow) actionHand();
    if (handle && handle->init())
    {
        handle->autorelease();
        return handle;
    }
    CC_SAFE_DELETE(handle);
    return nullptr;
}
bool actionHand:: init(){
    if(!Armature::init()){
        return false;
    }
    ArmatureDataManager::getInstance()->addArmatureFileInfo("gongnengyindao0.pvr.ccz", "gongnengyindao0.plist", "gongnengyindao.ExportJson");
    auto handle=Armature::create("gongnengyindao");
    handle->getAnimation()->playWithIndex(0,1,true);
    this->addChild(handle);
    return true;
}