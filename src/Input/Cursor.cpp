#include "Cursor.h"
#include "../glfw/glfw3.h"

inline void GLW::getCursorPos(GLFWwindow* window, double* xpos, double* ypos)
{
	glfwGetCursorPos(window, xpos, ypos);
}

inline void GLW::setCursorPos(GLFWwindow* window, double xpos, double ypos)
{
	glfwSetCursorPos(window, xpos, ypos);
}

inline GLFWcursor* GLW::createCursor(const GLFWimage* image, int xhot, int yhot)
{
	return glfwCreateCursor(image, xhot, yhot);
}

inline GLFWcursor* GLW::createStandardCursor(CursorShape shape)
{
	return glfwCreateStandardCursor(static_cast<int>(shape));
}

inline void GLW::destroyCursor(GLFWcursor* cursor)
{
	glfwDestroyCursor(cursor);
}

inline void GLW::setCursor(GLFWwindow* window, GLFWcursor* cursor)
{
	glfwSetCursor(window, cursor);
}