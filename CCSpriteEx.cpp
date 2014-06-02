#include "CCSpriteEx.h"
 
NS_CC_BEGIN
 
 
void CCSpriteEx::onEnter()
{
    CCSprite::onEnter();
    // ע�ᴥ��Э�飬���Ե������¼�
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0/*priority=??*/, true);
}
 
void CCSpriteEx::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}
 
cocos2d::CCRect CCSpriteEx::rect()
{
    return CCRectMake(getPositionX() - getContentSize().width * getAnchorPoint().x,
        getPositionY() - getContentSize().height * getAnchorPoint().y,
        getContentSize().width, getContentSize().height); // Ϊ���ܹ��Զ����Լ���λ�ô�С�����˵�Ч�ĺ���������ֱ���ó�Ա����
}
 
bool CCSpriteEx::isTouchInside( CCTouch* touch )
{
    CCPoint touchLocation = touch->getLocation(); // ����GL����
    bool isTouched = rc.containsPoint(touchLocation);
     
    return isTouched;
}
 
bool CCSpriteEx::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
    bool isTouched = isTouchInside(pTouch);
    return isTouched;
}
 
void CCSpriteEx::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
    bool isTouched = isTouchInside(pTouch) && isVisible();
    if (isTouched)
    {       
        if (m_pListener && m_pfnSelector)
        {
            (m_pListener->*m_pfnSelector)(this);
        }
    }
}
 
void CCSpriteEx::setSelectorWithTarget( CCObject *target, SEL_MenuHandler selector )
{
    m_pListener = target;
    m_pfnSelector = selector;
}
 
NS_CC_END