#pragma once

#include "Pleiades.h"
#include "Level.h"

// imgui
#include <imgui/imgui.h>

class GameLayer : public Pleiades::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Pleiades::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Pleiades::Event& e) override;
	bool OnMouseButtonPressed(Pleiades::MouseButtonPressedEvent& e);
	bool OnWindowResize(Pleiades::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Pleiades::Scope<Pleiades::OrthographicCamera> m_Camera;
	Level m_Level;
	ImFont* m_Font;
	float m_Time = 0.0f;
	bool m_Blink = false;

	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;
};