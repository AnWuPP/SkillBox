#include <iostream>

#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
#define SUNDAY "Sunday"

int main()
{
	int day = 1;
	while (day != -1) {
		std::cin >> day;
		
		switch (day) {
		case 1:
			std::cout << MONDAY << std::endl;
			break;
		case 2:
			std::cout << TUESDAY << std::endl;
			break;
		case 3:
			std::cout << WEDNESDAY << std::endl;
			break;
		case 4:
			std::cout << THURSDAY << std::endl;
			break;
		case 5:
			std::cout << FRIDAY << std::endl;
			break;
		case 6:
			std::cout << SATURDAY << std::endl;
			break;
		case 7:
			std::cout << SUNDAY << std::endl;
			break;
		default:
			std::cout << "Day not found" << std::endl;
		}
	}
	
}