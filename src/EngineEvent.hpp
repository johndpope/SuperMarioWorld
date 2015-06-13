#include <SFML/Graphics.hpp>
#include "MovingObject.hpp"

typedef enum
{
#ifdef DEBUG_MODE
	INFO_DEBUG,
#endif
	LEVEL_START,	// g to s
	GAME_STOPPED,
	KEY_PRESSED,	// gfx to g
	KEY_RELEASED,	// gfx to g
	INFO_POS_CHAR,	// g to gfx during game: character (Mario or enemy) position
	INFO_POS_LVL,	// gfx <-> g: position of a foreground sprite
	INFO_LVL,		// g to gfx when loading level: basing info about level
	PLAY_SOUND,
} EventType;

typedef enum
{
	JUMP_SND,
	COIN_SND,
	DEATH_SND
} SoundType;

struct LevelInfo
{
	std::string name;
	std::string backgroundName;
	sf::Vector2f size;
};

/* This class represents a message sent from an engine to another */
class EngineEvent
{
	public:

		EventType m_type;
		
		union
		{
			sf::Keyboard::Key m_key;
			struct { // Unnamed struct to fool VS which is being annoying..
				InfoForDisplay m_infoDisplay;
			};
			SoundType m_sound;
			int m_id;
		} data;
		std::string m_string; // A string can't be inside a union
		sf::Rect<float> m_rect;
		LevelInfo m_levelInfo;

#ifdef DEBUG_MODE
		DebugInfo m_debugInfo;
#endif

		void set(EventType _type)
		{
			m_type = _type;
			data.m_key = sf::Keyboard::Unknown;
		}

		void set(EventType _type, sf::Keyboard::Key _key)
		{
			m_type = _type;
			data.m_key = _key;
		}

		void set(EventType _type, InfoForDisplay _info)
		{
			m_type = _type;
			data.m_infoDisplay = _info;
		}

		void set(EventType _type, SoundType _sound)
		{
			m_type = _type;
			data.m_sound = _sound;
		}

		void set(EventType _type, std::string _str)
		{
			m_type = _type;
			m_string = _str;
		}

		void set(EventType _type, int _id, sf::Rect<float> _rect)
		{
			m_type = _type;
			data.m_id = _id;
			m_rect = _rect;
		}

		void set(EventType _type, LevelInfo _info)
		{
			m_type = _type;
			m_levelInfo = _info;
		}

#ifdef DEBUG_MODE
		void set(EventType _type, DebugInfo _info)
		{
			m_type = _type;
			m_debugInfo = _info;
		}
#endif
};