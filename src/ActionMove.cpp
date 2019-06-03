#include "ActionMove.h"
#include "ros/ros.h"

ActionMove::ActionMove() :
	ArAction("Follow"),
    m_ActionState(NoneUpdated),
    vel(0.0), 
    rotVel(0.0)
{

}

ActionMove::~ActionMove()
{
}

ArActionDesired *ActionMove::fire(ArActionDesired currentDesired)
{
	m_ActionDesired.reset();

    if (m_ActionState == NoneUpdated) {
        m_ActionDesired.setVel(0.0);
        m_ActionDesired.setRotVel(0.0);
    }
    else if (m_ActionState == Vels2Updated) {
        m_ActionDesired.setVel(vel);
        m_ActionDesired.setRotVel(rotVel);
        ROS_DEBUG("MoveAction: setting ActionDesired: v %f mm/s, w %f deg/s", vel, rotVel);
    }
    
    //m_ActionDesired.setHeading(th * 180.0 / M_PI);

	return &m_ActionDesired;
	
}

void ActionMove::setVels2(double vel, double rotVel)
{
    this->vel = vel;
    this->rotVel = rotVel;
    m_ActionState = Vels2Updated;
}