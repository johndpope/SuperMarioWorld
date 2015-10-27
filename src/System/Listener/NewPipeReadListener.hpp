#ifndef NEW_PIPE_READ_LISTENER_H
#define NEW_PIPE_READ_LISTENER_H

#include "../../EventEngine/Event.hpp"
#include "../../EventEngine/EventListener.hpp"
#include "../../Engines/GameEngine.hpp"
#include <string>

/**
* @author Kevin Guillaumond <kevin.guillaumond@gmail.com>
*/
class NewPipeReadListener : public EventListener
{
public:
	NewPipeReadListener(GameEngine* _gameEngine);

	/**
	* Called when an new_foreground_item_read event is dispatched
	* @param string eventType Type of received event
	* @param Event* event
	*/
	void onEvent(const std::string &_eventType, Event* _event);

private:
	GameEngine* m_gameEngine;
};

#endif // NEW_PIPE_READ_LISTENER_H
