// MIT License
//
// Copyright (c) 2023 Valerii Koniushenko
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "SFML/Graphics.hpp"

/**
 * @brief the base class for working with a game state.
 * @details for example you have a main menu and game process. Create two class and inherit from this one to create two game state.
 * Also, you need to register new game state in the enum class CustomEvent - create new state and go to Program.cpp. After that
 * open a function Program::ProcessCustomEvent and register your action like an answer for you Custom Event(e.g. Recreate game state
 * to get new GameState)
 * @code
 * class MainMenuGameState final : public GameStateBase
 * {
 * public:
 * 	MainMenuGameState() = default;
 * 	~MainMenuGameState() = default;
 * 	MainMenuGameState(MainMenuGameState&&) = default;
 * 	MainMenuGameState(const MainMenuGameState&) = default;
 * 	MainMenuGameState& operator=(MainMenuGameState&&) = default;
 * 	MainMenuGameState& operator=(const MainMenuGameState&) = default;
 *
 * void Prepare() override;
 * void Draw(sf::RenderWindow& Window) override;
 * void UpdateUi(sf::RenderWindow& Window) override;
 *
 * protected:
 * sf::Texture BackgroundTexture_;
 * sf::Texture ButtonTexture_;
 *
 * Button StartButton_;
 * Canvas BackgroundCanvas_;
 * };
 * @endcode
 * @code
 * if (Event == GameStateBase::CustomEvent::OpenGame)
 * {
 * 	GameState_.reset();
 * 	GameState_ = std::make_unique<GameProcessGameState>();
 * 	GameState_->Prepare();
 * }
 * @endcode
 */
class GameStateBase
{
public:
	// TODO: move it to *.data file and pull this data from that *.data file
	/**
	 * @brief Register your own event in this enum class to use it
	 */
	enum class CustomEvent : __int8
	{
		None,
		CloseGame,
		DefeatMenu,
		GoToMainMenu,
		OpenGame
	};

public:
	GameStateBase() = default;
	virtual ~GameStateBase() = default;
	GameStateBase(GameStateBase&&) = default;
	GameStateBase(const GameStateBase&) = default;
	GameStateBase& operator=(GameStateBase&&) = default;
	GameStateBase& operator=(const GameStateBase&) = default;

	/**
	 * @brief call this function BEFORE all to prepare this object.
	 * @details you can put in this function creating\loading of textures for scene objects.
	 */
	virtual void Prepare();

	/**
	 * @brief override this function to output all scene objects
	 */
	virtual void Draw(sf::RenderWindow& Window) = 0;

	/**
	 * @brief override this function to make a scene\state updater. Also, you can know this function by name 'Tick'
	 */
	virtual void UpdateUi(sf::RenderWindow& Window) = 0;

	/**
	 * @brief use this function to poll a one state-custom-event
	 */
	_NODISCARD CustomEvent PollEvent();

protected:
	sf::Font MainFont_;
	CustomEvent CustomEvent_ = CustomEvent::None;
};