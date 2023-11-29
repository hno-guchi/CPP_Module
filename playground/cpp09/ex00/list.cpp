#include <iostream>
#include <map>
#include <list>

static void	create(std::map<std::string, std::string> &map)
{
	map["name"] = "John";
	map["age"] = "21";
	map["city"] = "New York";
}

static void	addMap(std::list<std::map<std::string, std::string> > &list, std::map<std::string, std::string> &map)
{
	list.push_back(map);
}

static void	add(std::list<std::map<std::string, std::string> > &list)
{
	for	(int i = 0; i < 5; i++) {
		std::map<std::string, std::string>	map;

		create(map);
		addMap(list, map);
	}
}

static void	print(const std::list<std::map<std::string, std::string> >& list)
{
	for (std::list<std::map<std::string, std::string> >::const_iterator it = list.begin(); it != list.end(); it++)
	{
		for (std::map<std::string, std::string>::const_iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << it2->first << ": " << it2->second << std::endl;
		std::cout << std::endl;
	}
}

int	main()
{
	std::list<std::map<std::string, std::string> >	list;

	add(list);
	print(list);

	// system("leaks -q a.out");
}
