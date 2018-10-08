#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

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
	// TODO 4: Move all creation of bodies on 1,2,3 key press here in the scene

	// On space bar press, create a circle on mouse position
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->physics->createCircle(75,App->input->GetMouseX(),App->input->GetMouseY());
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		// TODO 1: When pressing 2, create a box on the mouse position
		// To have the box behave normally, set fixture's density to 1.0f

		App->physics->createRectangle(1,1,App->input->GetMouseX(),App->input->GetMouseY());

	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// TODO 2: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!

		int points[24] = {
			-38, 80,
			-44, -54,
			-16, -60,
			-16, -17,
			19, -19,
			19, -79,
			61, -77,
			57, 73,
			17, 78,
			20, 16,
			-25, 13,
			-9, 72
		};

		int elephant[112] = {
	24, 308,
	31, 259,
	60, 197,
	155, 98,
	264, 52,
	364, 47,
	450, 58,
	516, 49,
	577, 26,
	691, 33,
	775, 58,
	821, 104,
	859, 183,
	875, 302,
	846, 391,
	793, 454,
	731, 507,
	730, 538,
	759, 556,
	759, 575,
	733, 596,
	706, 603,
	674, 563,
	662, 516,
	677, 475,
	723, 426,
	723, 403,
	700, 393,
	612, 436,
	593, 467,
	588, 503,
	592, 543,
	623, 616,
	586, 628,
	499, 627,
	466, 615,
	473, 560,
	475, 515,
	458, 474,
	440, 460,
	385, 476,
	311, 455,
	286, 468,
	275, 496,
	287, 555,
	319, 614,
	283, 628,
	192, 624,
	153, 613,
	136, 593,
	151, 461,
	147, 414,
	106, 360,
	85, 315,
	71, 277,
	50, 298
		};


		App->physics->createChain(points, 24);

	}
	
	// TODO 6: Draw all the circles using "circle" texture

	return UPDATE_CONTINUE;
}
