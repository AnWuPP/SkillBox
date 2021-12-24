#include <iostream>

#define WINTER

#ifdef WINTER
int main()
{
	std::cout << "Winter" << std::endl;
}
#endif
#ifdef SPRING
int main()
{
	std::cout << "Spring" << std::endl;
}
#endif
#ifdef SUMMER
int main()
{
	std::cout << "Summer" << std::endl;
}
#endif
#ifdef AUTUMN
int main()
{
	std::cout << "Autumn" << std::endl;
}
#endif