#ifndef __CCSPRITEEX_H__
#define __CCSPRITEEX_H__
 
// CCSpriteEx �Ƕ� CCSprite�����չ����Ҫ���ܵõ������¼��ķ���
 
#include <cocos2d.h>
#include <cocos-ext.h>
 
NS_CC_BEGIN
 
class CCSpriteEx 
: public CCSprite
, public CCTargetedTouchDelegate
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCSpriteEx, create); // ����CocosBuilder
    // ���õ��������¼�������
    void setSelectorWithTarget(CCObject *target, SEL_MenuHandler selector);
 
public:
    CCSpriteEx() : m_pListener(NULL),m_pfnSelector(NULL) {}
 
private:
    void onEnter();
    void onExit();
    // ȡ�þ����λ����ߴ�
    CCRect rect();
    // �������Ƿ��ھ�����
    bool isTouchInside(CCTouch* touch);
 
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    // optional
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pEvent);}
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {CC_UNUSED_PARAM(pTouch); CC_UNUSED_PARAM(pEvent);}
 
private:
    // ����¼�����
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
 