#ifndef __CCSPRITEEX_H__
#define __CCSPRITEEX_H__
 
// CCSpriteEx 是对 CCSprite类的扩展，主要是能得到触摸事件的反馈
 
#include <cocos2d.h>
#include <cocos-ext.h>
 
NS_CC_BEGIN
 
class CCSpriteEx 
: public CCSprite
, public CCTargetedTouchDelegate
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCSpriteEx, create); // 用于CocosBuilder
    // 设置点击精灵的事件处理器
    void setSelectorWithTarget(CCObject *target, SEL_MenuHandler selector);
 
public:
    CCSpriteEx() : m_pListener(NULL),m_pfnSelector(NULL) {}
 
private:
    void onEnter();
    void onExit();
    // 取得精灵的位置与尺寸
    CCRect rect();
    // 触摸点是否在精灵上
    bool isTouchInside(CCTouch* touch);
 
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    // optional
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pEvent);}
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pEvent);}
 
private:
    // 点击事件处理
    CCObject*       m_pListener;
    SEL_MenuHandler m_pfnSelector;
};
 
class CCSpriteExLoader : public cocos2d::extension::CCSpriteLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCSpriteExLoader, loader);
 
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCSpriteEx);
};
 
NS_CC_END
 
#endif // __CCSPRITEEX_H__
 