/*
** EPITECH PROJECT, 2019
** SE.hpp
** File description:
** SE
*/

#ifndef SE_HPP_
#define SE_HPP_

#include <string>
#include <iostream>
#include <vector>
        
class SE {
public:
	enum TYPE {
		RECT,
		TXT
	};
	~SE(){}
	virtual SE::TYPE getType() = 0;
	virtual bool get_fixed() = 0;

};

class Rect : public SE {
public:
	Rect() { }
	~Rect() { }
    SE::TYPE getType() { return _type; }

	void set_pos(std::pair <int, int> tmp)
		{
			this->pos.second = tmp.first;
			this->pos.first = tmp.second;
		}

	void set_bool(bool tmp)
		{
			this->fix = tmp;
			return ;
		}
	void set_path(std::string tmp)
		{
			this->path.assign(tmp);
		}
	void set_color(std::string tmp)
		{
			this->color.assign(tmp);
		}
	bool get_fixed()
		{
			return fix;
		}
	std::pair<int, int> pos;
	std::pair<int, int> dim;
	std::string color;
	std::string path;
	SE::TYPE _type;
	bool fix;
};

class txt : public SE {
public:
	txt(){};
	~txt(){};
	SE::TYPE getType() { return _type; }
	void set_pos(std::pair <int, int> tmp)
		{
			this->pos.first = tmp.first;
			this->pos.second = tmp.second;
		}
	void set_bool(bool tmp)
		{
			this->fix = tmp;
			return ;
		}
	void set_path(int tmp)
		{
			this->font_path = tmp;
		}
	void set_txt(std::string value)
		{
			this->str.assign(value);
		}
	void set_color(std::string tmp)
		{
			this->color.assign(tmp);
		}
	bool get_fixed()
		{
			return fix;
		}
	std::pair<int, int> pos;
	std::pair<int, int> dim;
	std::string font_path;
	std::string color;
	std::string str;
	bool fix;
	SE::TYPE _type;
};

#endif /* !SE_HPP_ */
