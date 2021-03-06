#ifndef _MAP_HH_
# define _MAP_HH_

#include "CellType.hh"
#include "CellProperty.hh"
#include "Unit.hh"

class Map : public sf::Drawable, public sf::Transformable
{
public:
    Map();
    ~Map();

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    CellType getCell(unsigned int x, unsigned int y) const;
    CellProperty getCellProperties(unsigned int x, unsigned int y);
    sf::Vector2u getTilesize() const;
    static unsigned int getDistanceBetween(unsigned int firstX, unsigned int firstY, unsigned int secondX, unsigned int secondY);
	bool canGo(unsigned int x, unsigned int y, Unit const&);
	static CellType** parseMap(unsigned int const& width, unsigned int const& height);
    bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    unsigned int _width;
    unsigned int _height;
    CellType **_cells;
    sf::Vector2u _tileSize;
    sf::VertexArray _vertices;
    sf::Texture _tileset;
};


#endif
