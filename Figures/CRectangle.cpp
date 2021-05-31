#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{

	if (P1.x < P2.x)
	{
		Corner1 = P1;
		Corner2 = P2;
	}
	else
	{
		Corner1 = P2;
		Corner2 = P1;
	}

	ID = 4400 + newID++;
	area = float(abs((Corner1.x - Corner2.x) * (Corner1.y - Corner2.y)));
	Vec2 v1 = Vec2(Corner1.x, Corner1.y);
	Vec2 v2 = Vec2(Corner2.x, Corner2.y);
	Vec2 cent = ((v1 - v2) * 0.5f) + v2;
	center.x = int(cent.x);
	center.y = int(cent.y);
}

void CRectangle::Resize(float r)
{
	Vec2 v1 = Vec2(Corner1.x, Corner1.y);
	Vec2 v2 = Vec2(Corner2.x, Corner2.y);
	Vec2 cent = Vec2(center.x,center.y);
	if (r >= 0 && r < 1)
	{
		v1 = ((cent - v1) * (1 - r)) + v1;
		v2 = ((cent - v2) * (1 - r)) + v2;
	}
	else
	{
		v1 = cent - ((cent - v1) * r);
		v2 = cent - ((cent - v2) * r);
	}

	Corner1.x = int(v1.x);
	Corner1.y = int(v1.y);
	Corner2.x = int(v2.x);
	Corner2.y = int(v2.y);
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isInsideMe(Point p) const
{
	return p.x >= Corner1.x && p.x <= Corner2.x
		&& p.y >= Corner1.y && p.y <= Corner2.y;
}


//this function should be reImplemented to print the proper information
void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage(std::string("<<ID: ")+std::to_string(ID)+" <<Width: "+ std::to_string(std::abs(Corner1.x - Corner2.x))+" <<Height: "+ std::to_string(std::abs(Corner1.y - Corner2.y))+" <<Area: "+ std::to_string(int(area)) + " <<center: ( " + std::to_string(center.x) + ", " + std::to_string(center.y) + " )");
}

void CRectangle::Move(Point newPoint)
{
	Vec2 cor1 = Vec2(Corner1.x, Corner1.y);
	Vec2 cor2 = Vec2(Corner2.x, Corner2.y);
	Vec2 newP = Vec2(newPoint.x, newPoint.y);
	cor2 += (newP - cor1).GetNormalized() * (newP - cor1).GetLength();
	Corner1 = newPoint;
	Corner2.x = int(cor2.x);
	Corner2.y = int(cor2.y);
}

void CRectangle::moveBy(Vec2 incr)
{
	Vec2 newP = Vec2(Corner1.x, Corner1.y) + incr;
	Point newPoint = { int(newP.x), int(newP.y) };
	Move(newPoint);
}

Point CRectangle::getCriticalPoint() const
{
	return Corner1;
}

CFigure* CRectangle::getCopy() const
{
	return new CRectangle(Corner1, Corner2, FigGfxInfo);
}
