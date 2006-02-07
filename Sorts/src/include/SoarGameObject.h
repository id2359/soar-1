#ifndef SoarGameObject_H
#define SoarGameObject_H

#include"FSM.h"

#include<stack>
#include<vector>

//How do I transition from one FSM to another?

class SoarGameGroup;

class SoarGameObject{
 public:
	SoarGameObject(GameObj *);
	~SoarGameObject();

	void registerBehavior(FSM *);
	void removeBehavior(std::string cmd);

	void issueCommand(std::string name, Vector<sint4> p);
	void update();

	void setGroup(SoarGameGroup *g);
	SoarGameGroup *getGroup();

	GameObj *gob;
 private:
	std::list<FSM *> behaviors;
	std::stack<FSM *> memory;

  	SoarGameGroup* group;

};

#endif
