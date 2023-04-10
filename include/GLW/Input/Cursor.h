#pragma once

#include "../API.h"
#include "../Vector.h"

struct GLFWwindow;
struct GLFWcursor;
struct GLFWimage;

namespace GLW
{
	enum class CursorShape : int
	{
		ARROW = 0x00036001, IBEAM, CROSSHAIR, HAND, HRESIZE, VRESIZE
	};

	namespace Cursor
	{
		//Retrieves the position of the cursor relative to the content area of the window
		GLW_API void getCursorPos(GLFWwindow* window, double* xpos, double* ypos);
		//Retrieves the position of the cursor relative to the content area of the window
		static inline dvec2 getCursorPos(GLFWwindow* window)
		{
			dvec2 temp;
			getCursorPos(window, &temp.x, &temp.y);
			return temp;
		}

		//Sets the position of the cursor, relative to the content area of the window
		GLW_API void setCursorPos(GLFWwindow* window, double xpos, double ypos);
		//Sets the position of the cursor, relative to the content area of the window
		static void setCursorPos(GLFWwindow* window, const dvec2& pos)
		{
			setCursorPos(window, pos.x, pos.y);
		}

		//Creates a custom cursor
		GLW_API GLFWcursor* createCursor(const GLFWimage* image, int xhot, int yhot);

		//Creates a cursor with a standard shape
		GLW_API GLFWcursor* createStandardCursor(CursorShape shape);

		//Destroys a cursor
		GLW_API void destroyCursor(GLFWcursor* cursor);

		//Sets the cursor for the window
		GLW_API void setCursor(GLFWwindow* window, GLFWcursor* cursor);
	}
}