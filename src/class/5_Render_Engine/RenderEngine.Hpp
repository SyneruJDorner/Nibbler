#ifndef RENDERENGINE_HPP
# define RENDERENGINE_HPP

# include <string>

class RenderEngine
{
	public:
		RenderEngine();
		RenderEngine(RenderEngine &obj);
		virtual ~RenderEngine();
		RenderEngine &operator=(RenderEngine const &other);
};

#endif