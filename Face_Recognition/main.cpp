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
}
catch (const std::exception& e)
{
	cout << e.what() << endl;
}