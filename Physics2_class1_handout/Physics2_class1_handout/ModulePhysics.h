#pragma once
#include "Module.h"
#include "Globals.h"


class b2World;
#define PIXELS_TO_METERS(pixels) {float(pixels/conversionfactor)}
#define METERS_TO_PIXELS(meters) {(int)(meters*conversionfactor)}


class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();



private:

	b2World *world;
	bool debug;
	int radius;
	int conversionfactor = 10;

};