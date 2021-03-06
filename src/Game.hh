#ifndef _GAME_HH_
# define _GAME_HH_

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include "Chat.hh"
#include "Cscreen.hh"
#include "Direction.hh"
#include "Map.hh"
#include "Menu.hh"
#include "Player.hh"
#include "Star.hh"
#include "Unit.hh"

class Game : public Cscreen
{
public:
    Game(unsigned int width, unsigned int height, Menu const& menu);
    ~Game();

	Chat& getChat();
    std::vector<sf::Vector2u> getPosReachable(Unit const& unit);
    std::vector<sf::Vector2u> getColateral(unsigned int x, unsigned int y, Unit const& unit);
    std::vector<Unit*> getInRange(unsigned int x, unsigned int y, unsigned int rangeMin, unsigned int rangeMax, UnitField field);
    void setMap(Map map);
    void initPlayers();
    bool canPlaceUnit(unsigned int x, unsigned int y, Unit const& unit);
    bool placeUnit(Unit& unit);
    bool addUnit(Unit& unit);
	static bool isReachable(sf::Vector2i coord, std::vector<sf::Vector2u> posReachable);
    void resetUnits();
	void cleanDeadUnits();
    void newTurn();
    bool didLose(Player const& player);
	static void recalibratePosition(sf::Vector2i& pixelCoord);
	void convertPixelToCoord(sf::Vector2i& pixelCoord);
	bool askPlaceUnits(sf::RenderWindow &window, Player& player);
    sf::Vector2i askAttack(sf::RenderWindow &window, Unit const& unit);
    void moveUnit(Unit& unit, Direction direction, unsigned int n);
    bool loadUnits(const std::string& tileset, sf::Vector2u tileSize);
    bool reloadItems();
    void drawItems(sf::RenderWindow &window);
    int Run(sf::RenderWindow &window) override;
private:
    unsigned int _width;
    unsigned int _height;
	Chat _chat;
    Map _map;
	Star _star;
    Menu const& _menu;
    std::vector<Player*> _players;
    std::vector<Unit*> _units;
};

#endif /*_GAME_HH_*/
