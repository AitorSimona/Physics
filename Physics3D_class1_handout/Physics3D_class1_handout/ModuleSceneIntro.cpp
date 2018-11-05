#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center

	App->camera->Position.x = 1;
	App->camera->Position.y = 1;

	vec3 camerapos = { 0,0,0 };
	App->camera->LookAt(camerapos);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	Plane aux;

	aux.axis = true;
	aux.color = Red;
	aux.normal = { 0,0,0 };
	aux.Render();
	aux.InnerRender();

	Sphere aux2;
	aux2.axis = true;
	aux2.color = Blue;
	aux2.radius = 0.5f;
	aux2.Render();

	Cube aux3;
	aux3.axis = true;
	aux3.color = Green;
	aux3.size = 1;
	aux3.SetPos(2,2,0);
	aux3.wire = true;
	aux3.Render();

	Cylinder aux4;
	aux4.axis = true;
	aux4.color = White;
	aux4.radius = 0.5f;
	aux4.height = 2;
	aux4.SetPos(-2,0,0);
	aux4.wire = true;
	aux4.SetRotation(45,vec3(0,0,1));
	aux4.Render();



	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	return UPDATE_CONTINUE;
}

