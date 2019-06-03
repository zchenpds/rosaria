#pragma once

#include "Aria.h"
//#include "Config.h"

enum ActionMoveState {
    NoneUpdated = 0,
    Vels2Updated = 1
};

class ActionMove : public ArAction
{
public:
	ActionMove();
	~ActionMove();
	// fire, this is what the resolver calls to figure out what this action wants
	virtual ArActionDesired *fire(ArActionDesired currentDesired);
    
    void setVels2(double vel, double rotVel);
protected:
	//ArRobot*			m_pArRobot;
	ArActionDesired		m_ActionDesired;
    ActionMoveState     m_ActionState;
    double vel;
    double rotVel;
};
