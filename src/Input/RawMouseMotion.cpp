#include "RawMouseMotion.h"
#include "../glfw/glfw3.h"

inline bool GLW::RawMouseMotion::rawMouseMotionSupported()
{
	return glfwRawMouseMotionSupported();
}
