#include <iostream>
#include <map>
#include <vector>
#include <cpr/cpr.h>

int main() {
	std::map<std::string, std::string> args;
	std::string buf1, buf2;

	while (true) {
		std::cin >> buf1;
		if (buf1 == "post") {
			if (args.empty()) {
				std::cout << "No data for request" << std::endl;
				continue;
			}
			std::vector<cpr::Pair> data;
			for (auto& a : args) {
				data.push_back({ a.first, a.second });
			}
			args.clear();
			cpr::Response r = cpr::Post(cpr::Url{ "http://httpbin.org/post" },
				cpr::Payload(data.begin(), data.end())
			);
			std::cout << r.text << std::endl;
		}
		else if (buf1 == "get") {
			if (args.empty()) {
				std::cout << "No data for request" << std::endl;
				continue;
			}
			std::string data = "?";
			for (auto& v : args) {
				data += v.first + "=" + v.second + "&";
			}
			data.erase(--data.end());
			args.clear();
			cpr::Response r = cpr::Get(cpr::Url{ "http://httpbin.org/get" + data });
			std::cout << r.text << std::endl;
		}
		else {
			std::cin >> buf2;
			args.insert(std::make_pair(buf1, buf2));
		}
	}
}
