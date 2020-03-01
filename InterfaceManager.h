#pragma once
#include "Objects/PluginAPI/PluginManager.h"
#include "Objects/DebugInformation.h"
#include "Objects/PipelineManager.h"
#include "Objects/ObjectManager.h"
#include "Objects/ProjectParser.h"
#include "Objects/RenderEngine.h"
#include "Objects/MessageStack.h"
#include <SDL2/SDL_events.h>

namespace ed
{
	class GUIManager;

	class InterfaceManager
	{
	public:
		InterfaceManager(GUIManager* gui);
		~InterfaceManager();

		void OnEvent(const SDL_Event& e);
		void Update(float delta);

		bool FetchPixel(PixelInformation& pixel);

		PluginManager Plugins;
		RenderEngine Renderer;
		PipelineManager Pipeline;
		ObjectManager Objects;
		ProjectParser Parser;
		MessageStack Messages;
		DebugInformation Debugger;

	private:
		GUIManager* m_ui;
	};
}