#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
private:
	ActionType actAfterSelect;
	CFigure** selectedFigures; // array of selected figures that maps the figList in appManager 
	CFigure* firstSelectedFigure;//pointer to the first selected figure
	int* numberedClicked;//array of numbers that maps the clicked figure to number of clicked actions
	int countClicked;//counter to the clicked actions
	int selectedFigCount;	//count of figure selected

private:
	CFigure* getThatFigure() const; //getting the only figure that is selected "gauranteed that is one figure selected"

	void executeActionAfterSelect(ActionType);//exectueing the action after select

	int getIndexOfFirstSelected() const;//get the first figure selected 
public:
	Select(ApplicationManager* mApp);
	
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();



	virtual ~Select();

};
