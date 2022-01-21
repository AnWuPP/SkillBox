#include <iostream>
#include <cpr/cpr.h>

int main()
{
	std::string buf = "";

	std::cout << "Use commands: get, post, patch, delete, put. ext for exit" << std::endl;
	while (buf != "ext") {
		std::cin >> buf;
		if (buf == "get") {
			cpr::Response r = cpr::Get(cpr::Url{ "http://httpbin.org/" + buf });
			std::cout << r.text << std::endl;
		}
		else if (buf == "post") {
			cpr::Response r = cpr::Post(cpr::Url{ "http://httpbin.org/" + buf });
			std::cout << r.text << std::endl;
		}
		else if (buf == "patch") {
			cpr::Response r = cpr::Patch(cpr::Url{ "http://httpbin.org/" + buf });
			std::cout << r.text << std::endl;
		}
		else if (buf == "put") {
			cpr::Response r = cpr::Put(cpr::Url{ "http://httpbin.org/" + buf });
			std::cout << r.text << std::endl;
		}
		else if (buf == "delete") {
			cpr::Response r = cpr::Delete(cpr::Url{ "http://httpbin.org/" + buf });
			std::cout << r.text << std::endl;
		}
	}
}
