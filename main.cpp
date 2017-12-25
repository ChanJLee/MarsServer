#include <iostream>
#include <fstream>
#include <cstddef>
int main(int argc, char *argv[])
{
	std::cout << "Hello, World!" << std::endl;
	std::ifstream is("/Users/chan/Downloads/x.yuv", std::ios::binary);
	std::ofstream os("/Users/chan/Downloads/out.yuv", std::ios::binary);
	std::streamsize size = 96000;
	char buffer[size];
	is.read(buffer, size);
	std::streamsize len = is.gcount();
	os.write(buffer, len);
	std::cout << "len: " << len << std::endl;
	return 0;
}