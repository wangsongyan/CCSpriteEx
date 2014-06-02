#include "CCSpriteEx.h"
 
NS_CC_BEGIN
 
 
void CCSpriteEx::onEnter()
{
    CCSprite::onEnter();
    // 注册触摸协议，并吃掉触摸事件
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
        getContentSize().width, getContentSize().height); // 为了能够自定义自己的位置大小采用了低效的函数而不是直接用成员变量
}
 
bool CCSpriteEx::isTouchInside( CCTouch* touch )
{
    CCPoint touchLocation = touch->getLocation(); // 返回GL坐标
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