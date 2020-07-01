#define DLIB_JPEG_SUPPORT

#include <vector>
#include <iostream>
#include <io.h>
#include <string>
#include <dlib/image_io.h>
#include <dlib/gui_widgets/widgets.h>

#include "face_encode.h"

using namespace dlib;


void find_face(std::vector<std::pair<std::string, matrix<float, 0, 1>>>& db);


int main()try
{
	std::vector<std::pair<std::string, matrix<float, 0, 1>>> db;

	std::string data_path = ".\\faces";
	long h_file;
	std::intptr_t folder_handle;
	std::intptr_t img_handle;
	_finddata_t file_search;
	_finddata_t img_search;

	face_encode face_encoder;
	
	
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

			try
			{
				db.push_back(std::make_pair(Name, face_encoder.get_face_descriptors(img)));
			}
			catch(const char* e_str)
			{
				std::cerr << e_str << std::endl;
			}
			catch (const std::exception & e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch (...)
			{
				std::cerr << "Unkown exception : Cant encode this face!!\n" << std::endl;
			}
			

		} while (_findnext(img_handle, &img_search) == 0);

		std::cout << std::endl;
		_findclose(img_handle);
	} while (_findnext(folder_handle, &file_search) == 0); 
	

	// ------------------------------end face encoding-----------------------------------------

	while (1)
	{
		find_face(db);
	}


}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;
}
catch (...)
{
	std::cerr << "Unkown exception\n" << std::endl;
}


void find_face(std::vector<std::pair<std::string, matrix<float, 0, 1>>>& db)
{
	face_encode face_encoder;
	string test_img_path;

	std::cin >> test_img_path;

	matrix<rgb_pixel> test_img;

	load_image(test_img, test_img_path);

	matrix<float, 0, 1> test_encode = face_encoder.get_face_descriptors(test_img);

	std::pair<std::string, float> min = std::make_pair("Unknown", 0.35);

	for (auto i : db)
	{
		float v = length(test_encode - i.second);
		if (v < min.second)
		{
			min.first = i.first;
			min.second = v;
		}
	}

	std::cout << "가장 비슷함 : " << min.first << std::endl;
	std::cout << "유사도 : " << min.second << std::endl;
	std::cout << std::endl;
}