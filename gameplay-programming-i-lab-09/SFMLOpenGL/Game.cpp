#include <Game.h>

static bool flip;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[8];
GLubyte triangles[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;



void Game::initialize()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -8);
	glEnable(GL_CULL_FACE);

	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	vertex[0].coordinate[0] = -1.0f;
	vertex[0].coordinate[1] = -1.0f;
	vertex[0].coordinate[2] = 1.0f;

	vertex[1].coordinate[0] = 1.0f;
	vertex[1].coordinate[1] = -1.0f;
	vertex[1].coordinate[2] = 1.0f;

	vertex[2].coordinate[0] = 1.0f;
	vertex[2].coordinate[1] = 1.0f;
	vertex[2].coordinate[2] = 1.0f;

	vertex[3].coordinate[0] = -1.0f; 
	vertex[3].coordinate[1] = 1.0f;  
	vertex[3].coordinate[2] = 1.0f;

	vertex[4].coordinate[0] = -1.0f; 
	vertex[4].coordinate[1] = -1.0f;  
	vertex[4].coordinate[2] = -1.0f;

	vertex[5].coordinate[0] = 1.0f; 
	vertex[5].coordinate[1] = -1.0f;  
	vertex[5].coordinate[2] = -1.0f;

	vertex[6].coordinate[0] = 1.0f;
	vertex[6].coordinate[1] = 1.0f;
	vertex[6].coordinate[2] = -1.0f;

	vertex[7].coordinate[0] = -1.0f;
	vertex[7].coordinate[1] = 1.0f;
	vertex[7].coordinate[2] = -1.0f;

	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 1.0f;
	vertex[1].color[1] = 0.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 0.6f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 1.0f;

	vertex[7].color[0] = 0.6f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;

	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 2;   triangles[4] = 3;   triangles[5] = 0;
	triangles[6] = 5;   triangles[7] = 1;   triangles[8] = 0;
	triangles[9] = 0;   triangles[10] = 4;   triangles[11] = 5;
	triangles[12] = 1;   triangles[13] = 5;   triangles[14] = 6;
	triangles[15] = 6;   triangles[16] = 2;   triangles[17] = 1;
	triangles[18] = 3;   triangles[19] = 2;   triangles[20] = 6;
	triangles[21] = 6;   triangles[22] = 7;   triangles[23] = 3;
	triangles[24] = 4;   triangles[25] = 0;   triangles[26] = 3;
	triangles[27] = 3;   triangles[28] = 7;   triangles[29] = 4;
	triangles[30] = 6;   triangles[31] = 5;   triangles[32] = 4;
	triangles[33] = 4;   triangles[34] = 7;   triangles[35] = 6;
	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f/60.0f)
	{
		clock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			for (int i = 0; i < 8; i++)
			{

				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.rotationZ(0.01) * vector;
				vertex[i].coordinate[0]=vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = vector.z;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			for (int i = 0; i < 8; i++)
			{


				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.rotationY(0.01) * vector;
				vertex[i].coordinate[0] = vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = vector.z;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			for (int i = 0; i < 8; i++)
			{
				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.rotationX(0.01) * vector;
				vertex[i].coordinate[0] = vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = vector.z;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			for (int i = 0; i < 8; i ++)
			{
				float z = vertex[i].coordinate[2];
				vertex[i].coordinate[2] = 1;
				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.translation({ 0.01, 0.01, 0.0 }) * vector;
				vertex[i].coordinate[0] = vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = z;

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			for (int i = 0; i < 8; i++)
			{
				
				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.scale(1.01) * vector;
				vertex[i].coordinate[0] = vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = vector.z;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			for (int i = 0; i < 8; i++)
			{
				
				vector.x = vertex[i].coordinate[0];
				vector.y = vertex[i].coordinate[1];
				vector.z = vertex[i].coordinate[2];
				vector = matrix.scale(0.99) * vector;
				vertex[i].coordinate[0] = vector.x;
				vertex[i].coordinate[1] = vector.y;
				vertex[i].coordinate[2] = vector.z;
			}
		}
	}

	



	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

