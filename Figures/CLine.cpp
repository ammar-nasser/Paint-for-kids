#include "CLine.h"

CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	if (p1.x < p2.x)
	{
		start = p1;
		finish = p2;
	}
	else
	{
		start = p2;
		finish = p1;
	}
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(start,finish, FigGfxInfo, Selected);
}

bool CLine::isInsideMe(Point p) const 
{ 
	if (p.x <= finish.x && p.x >= start.x)
	{
		float grad1 = (float(finish.y - start.y) / (finish.x - start.x));
		float grad2 = (float(p.y - start.y) / (p.x - start.x));
		return std::abs(grad1 - grad2) >= 0.0f && std::abs(grad1 - grad2) <= 0.1f;
	}
	return false;
	
}

 void CLine::PrintInfo(Output* pOut) const
 {
 }

 void CLine::Move(Point newPoint)
 {
	 Vec2 strt = Vec2(start.x, start.y);
	 Vec2 end = Vec2(finish.x, finish.y);
	 Vec2 newP = Vec2(newPoint.x, newPoint.y);

	 end += (newP - strt).GetNormalized() * (newP - strt).GetLength();

	 start = newPoint;
	 finish = { int(end.x), int(end.y) };
 }
