#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../System/Engine.hpp"
#include "CollisionHandler.hpp"
#include "LevelImporter.hpp"
#include "../System/Items/Box.hpp"
#include "../System/Characters/Goomba.hpp"

/*
    Game engine: Handles the movements of the player, collisions, etc.
*/
class GameEngine : public Engine
{
    public:
        GameEngine(EventEngine*);
        ~GameEngine();

		void Frame();
		void Frame(float _dt);

		void StoreLevelInfo(LevelInfo* _info);

		void AddCharacterToArray(MovingObject *_character);
		void AddForegroundItemToArray(DisplayableObject *_item);
		void AddPipeToArray(Pipe *_pipe);

		void UpdateForegroundItem(unsigned int _id, sf::FloatRect _coordinates);

		void KillCharacter(unsigned int _characterID);

		void HandlePressedKey(sf::Keyboard::Key _key);
		void HandleReleasedKey(sf::Keyboard::Key _key);

		void ToggleIgnoreUserInput(bool _ignore);

		/* Getters / setters for LevelImporter */
		void SetMarioInitialPosition(sf::Vector2f _pos) { m_initPosMario = _pos; };

		/* Getters / setters for Collisionhandler */
		DisplayableObject *GetForegroundItem(unsigned int _id) { return m_listForegroundItems[_id]; };
		const sf::Vector2f GetCoordinatesOfForegroundItem(unsigned int _id) { return m_listForegroundItems[_id]->GetPosition(); };

    private:
		virtual void CreateListeners();

		CollisionHandler *m_collisionHandler;
		LevelImporter *m_levelImporter;

		sf::Vector2f m_initPosMario;
		int m_indexMario; // Index of Mario in m_characters. -1 if he's not in it.

		std::vector<MovingObject*> m_characters;
		std::map<unsigned int, DisplayableObject*> m_listForegroundItems; // Part of the level the characters can be in collision with. Pointers stored to allow polymorphism.
		std::map<unsigned int, Pipe*> m_listPipes;

		bool CanRespawnMario();

		void UpdateCharacterPosition(MovingObject& _character, float _dt);
		void SendCharacterPosition(int _indexCharacter);

		void DeleteAllDeadCharacters();

		void StartLevel(std::string _lvlName);
		std::string m_currentLevelName;
		bool m_levelStarted;

		void HandleCollisions(MovingObject& _obj);

		bool m_ignoreUserInput; // No input is taken into account while this sound is playing [see sound engine]

#ifdef DEBUG_MODE
		DebugInfo *m_debugInfo;
#endif
};

#endif // GAMEENGINE_H
