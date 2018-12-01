#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// TODO 2: Chain few N spheres together to form a snake

	//vec3 anchor(0, 0, s_snake[0].radius);

	//s_snake[0].SetPos(0, 0,s_snake[0].radius);

	//s_snake[1].SetPos(0, 0, s_snake[0].radius);
	//

	//pb_snake[0] = App->physics->AddBody(s_snake[0]);

	//pb_snake[1] = App->physics->AddBody(s_snake[1]);

	//App->physics->AddConstraintP2P(*pb_snake[0], *pb_snake[1], anchor, anchor);


	vec3 anchor(0, 0, s_snake[0].radius);

	s_snake[0].SetPos(0, 0, 0);

	pb_snake[0] = App->physics->AddBody(s_snake[0]);


	for (int i = 1; i < MAX_SNAKE; ++i)
	{
		s_snake[i].SetPos(0, 0 , i);

		pb_snake[i] = App->physics->AddBody(s_snake[i]);

		App->physics->AddConstraintP2P(*pb_snake[i], *pb_snake[i - 1], anchor, -anchor);
	}

	// TODO 4: Chain few N spheres together to form a a bike's sphere
	// Be sure to put the right axis

	vec3 anchor2(0, 0, s_snake2[0].radius);
	vec3 axis(0, 1, 0);

	s_snake2[0].SetPos(0, 0, 0);

	pb_snake2[0] = App->physics->AddBody(s_snake2[0]);


	for (int i = 1; i < MAX_SNAKE; ++i)
	{
		s_snake2[i].SetPos(0, 0, i);

		pb_snake2[i] = App->physics->AddBody(s_snake2[i]);

		App->physics->AddConstraintHinge(*pb_snake2[i], *pb_snake2[i - 1], anchor2, -anchor2, axis, axis);
	}

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	 //Uncomment when ready
	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake[i]->GetTransform(&(s_snake[i].transform));
		s_snake[i].color = Red;
		s_snake[i].Render();
	}

	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake2[i]->GetTransform(&(s_snake2[i].transform));
		s_snake2[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

