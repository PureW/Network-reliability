#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <GL/glfw.h>   // For GLFW, OpenGL and GLU
#include <GL/glpng.h>	// For png-loading

#include <string>
#include <sstream>




/** The constant fps that the game should run on */
const int fixedfps = 30;

enum fileType {
		TGA=1,
		BMP,
		PNG
};
enum G_Error {
		G_NO_ERROR=0,
		G_NO_SUCH_FILE,
		G_GLFW_ERROR,
		G_GLPNG_ERROR,
		G_GLU_ERROR,
		G_POINTER_ERROR,
		G_NO_SUPPORTED_FORMAT,
};

/** The class used for texture encapsulation.

 *  More detail */
class texture
{
public:
	GLuint data;		//< The GLuint used in calls to OpenGL
	int width, height;	//< Width and height of the original file
	float alpha;		//< Alpha value, only for png's
	texture() {};
	~texture() {glDeleteTextures(1, &data);};
private:

};

extern texture allText[30];


/** Main class for taking care of OpenGL-abstraction. Handles initialization, updating, drawing. */
class rendererAllmighty
{
public:
	/** Will try to initialize an OpenGL context.
	 *  More details */
	bool initWindow(int width, int height, int bpp, int mode, char* title );

	/** Sets the view to orthographic
	 *  More details */
	void setOrtho();

	/** Loads a texture.
	 *  More details */
	G_Error loadTexture( char* file, fileType type, texture* text );

	/** Draws a sprite
	 *  More detail */
	void drawSprite( texture* sprite, int x, int y, int width, int height, float rotation, float blended );
	void drawSprite( texture* sprite, int x, int y);
	void drawSprite( texture* sprite, int x, int y, int width, int height);
	void drawSprite( texture* sprite, int x, int y, float rotation, float blended );

	/** Draw a rectangle
	 *  More detail */
	void drawRectangle( int x, int y, int w, int h, float r, float b, float g, float alpha );


	/** Swap the buffers
	 *  More detail */
	void swapBuffers();

	rendererAllmighty() {};
	~rendererAllmighty() { glfwTerminate(); };

};












#endif




