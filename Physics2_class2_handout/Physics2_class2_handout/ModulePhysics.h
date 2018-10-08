#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

class b2World;
class b2Body;

//TODO 5: Create a small class that keeps a pointer to the b2Body
// and has a method to request the position
// then write the implementation in the .cpp
// Then make your circle creation function to return a pointer to that class

class Phys_Body {
	b2Body* bodydata;
	p2Point <int> GetPosition()
	{


	}

	//GetRotation will give radians, need to convert to degrees. create a macro for this
};


class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	// TODO 3: Move body creation to 3 functions to create circles, rectangles and chains

	void createCircle(int radius, int posx, int posy);
	void createRectangle(int width, int height, int posx, int posy);
	void createChain(int *points, const int count);
	

private:

	bool debug;
	b2World* world;
};