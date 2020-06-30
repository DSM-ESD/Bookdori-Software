#define DLIB_JPEG_SUPPORT

#include <vector>
#include <iostream>
#include <io.h>
#include <string>
#include <dlib/image_io.h>

//#include "face_encode.h"

using namespace dlib;

int main()try
{
	std::string data_path = ".\\faces";
	long h_file;
	std::intptr_t folder_handle;
	std::intptr_t img_handle;
	_finddata_t file_search;
	_finddata_t img_search;

	if ((folder_handle = _findfirst((data_path + "\\*.*").c_str(), &file_search)) == -1L)
	{
		throw std::logic_error(data_path + " 폴더 없음.");
	}

	do
	{
		std::string Name = file_search.name;
		std::cout << "폴더명 : " << Name << std::endl;

		if ((img_handle = _findfirst((data_path + "\\" + Name + "\\*.jpg*").c_str(), &img_search)) == -1L)
		{
			std::cout << "이미지가 없습니다" << std::endl;
			std::cout << std::endl;
			continue;
		}

		do
		{
			matrix<rgb_pixel> img;
			std::string img_Path = img_search.name;
			std::cout << "파일명 : " << img_Path << std::endl;
			load_image(img, data_path + "\\" + Name + "\\" + img_Path);


		} while (_findnext(img_handle, &img_search) == 0);

		std::cout << std::endl;
		_findclose(img_handle);
	} while (_findnext(folder_handle, &file_search) == 0);

	std::cout << "hit enter to terminate" << std::endl;
	std::cin.get();
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;
}
catch (...)
{
	std::cerr << "Unkown exception\n" << std::endl;
}