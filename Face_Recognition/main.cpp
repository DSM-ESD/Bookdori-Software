#include <iostream>
#include <io.h>
#include <string>

#include "face_encode.h"


using namespace std;


int main()try
{
	string data_path = ".\\faces";
	long h_file;
	intptr_t folder_handle;
	intptr_t img_handle;
	_finddata_t file_search;
	_finddata_t img_search;

	if ((folder_handle = _findfirst((data_path + "\\*.*").c_str(), &file_search)) == -1L)
	{
		throw logic_error(data_path + " 폴더 없음.");
	}
}
catch (const std::exception& e)
{
	cerr << e.what() << endl;
}
catch (...)
{
	cerr << "Unkown exception\n" << endl;
}