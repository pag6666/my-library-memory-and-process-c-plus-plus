#include"library.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	//make template
	const wchar_t* window_name = L"Загрузки";
	HWND window_hwnd;
	DWORD process_id;
	HANDLE process_handle;
	wcout << "find hwnd programm -> " << window_name << endl;
	get_hwnd_from_name(window_hwnd, window_name, wait_time_one_seconds);
	get_process_id(window_hwnd, process_id);
	get_process_handle(PROCESS_ALL_ACCESS, process_id, process_handle);
	cout << "window_hwnd = " << window_hwnd << endl;
	cout << "process_id = " << process_id << endl;
	cout << "process_handle = " << process_handle << endl;
	int temp;
	int i = 1;
	DWORD addres = 0x000000000009735C;
	int* ptr = (int*)addres;
	int buffer = 34;
	
	cout << memory_write(process_handle, ptr+i, buffer) << endl;
	temp = memory_read<int>(process_handle, ptr+i);
	cout << "ptr = " << ptr+i << endl;
	cout << "temp = " << temp << endl;
	cout << "buffer = " << buffer << endl;
	
}