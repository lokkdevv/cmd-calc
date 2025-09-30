#include <iostream>
#include <array>
#include <cctype>

int main()
{
	const size_t bufferSize = 1024;
	size_t bufferIndex = 0;
	std::array<std::string, bufferSize> buffer;

	std::string input;
	std::getline(std::cin, input);

	for(auto s : input)
	{
		if(isalpha(s))
		{
			continue;
		}
		if(isdigit(s) || s == '.')  // number or decimal
		{
			buffer.at(bufferIndex).push_back(s);
		}
		else if(!isblank(s))
		{
			if(!buffer.at(bufferIndex).empty())
				bufferIndex++;
			buffer.at(bufferIndex).push_back(s);
			bufferIndex++;
		}
	}
	for(size_t i = 0; i <= bufferIndex; ++i)
	{
		if(buffer[i].empty())
			break;
		std::cout << '"' << buffer[i] << "\"\n";
	}
	std::cin.get();
}