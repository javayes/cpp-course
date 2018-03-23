// 瓦瓦类的实现
#include "XWawa.h"

XWawa::XWawa() : moveCount(0)
{
	space.paint();
}

void XWawa::moveUp()
{
	if (space.moveWawa(XWAWAROOM_DIR_UP)) moveCount++;
}

void XWawa::moveDown()
{
	if (space.moveWawa(XWAWAROOM_DIR_DOWN)) moveCount++;
}

void XWawa::moveLeft()
{
	if (space.moveWawa(XWAWAROOM_DIR_LEFT)) moveCount++;
}

void XWawa::moveRight()
{
	if (space.moveWawa(XWAWAROOM_DIR_RIGHT)) moveCount++;
}

void XWawa::pickupBean()
{
	int x, y;
	space.getWawaPos(x, y);
	if (space.getPoint(x, y) == XWAWAROOM_BEAN)
	{
		space.setPoint(x, y, XWAWAROOM_EMPTY);
	}
}

void XWawa::putdownBean()
{
	int x, y;
	space.getWawaPos(x, y);
	space.setPoint(x, y, XWAWAROOM_BEAN);
}

bool XWawa::leftIsClear()
{
	return space.isClear(XWAWAROOM_DIR_LEFT);
}

bool XWawa::rightIsClear()
{
	return space.isClear(XWAWAROOM_DIR_RIGHT);
}

bool XWawa::upsideIsClear()
{
	return space.isClear(XWAWAROOM_DIR_UP);
}

bool XWawa::downsideIsClear()
{
	return space.isClear(XWAWAROOM_DIR_DOWN);
}

bool XWawa::beanIsHere()
{
	int x, y;
	space.getWawaPos(x, y);
	if (space.getPoint(x, y) == XWAWAROOM_BEAN)
		return true;
	else
		return false;
}

void XWawa::assignTask(int task)
{
	space.build(task);
	moveCount = 0;
}

bool XWawa::taskIsAccomplished()
{
	return space.check();
}
