#include "RawMouseMotion.h"
#include "../glfw/glfw3.h"

inline bool GLW::rawMouseMotionSupported()
{
	return glfwRawMouseMotionSupported();
}
