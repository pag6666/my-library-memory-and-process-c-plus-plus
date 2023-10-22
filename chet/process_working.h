#pragma once
#include<Windows.h>
#define MESSAGE_ERROR L"ERROR"
#define MESSAGE_SUCCESS L"SUCESS"
int INVALID_HANDLER_MESSAGE = -1;
int wait_time_one_seconds = 1000;
int wait_time_one_milliseconds = 1;
void error(const wchar_t* title, const wchar_t* error_message)
{
	MessageBox(nullptr, error_message, title, NULL);
	exit(INVALID_HANDLER_MESSAGE);
}
void send_message(const wchar_t* title, const wchar_t* message)
{
	MessageBox(nullptr, message, title, NULL);
}
void get_hwnd_from_name(HWND& window_hwnd, const wchar_t* window_name, int time_wait = wait_time_one_seconds)
{
	do {
		window_hwnd = FindWindow(NULL, window_name);
		Sleep(time_wait);
	} while (!window_hwnd);
}
void get_process_id(HWND window_hwnd, DWORD& process_id)
{
	DWORD checkerror = GetWindowThreadProcessId(window_hwnd, &process_id);
	if (!checkerror)
		error(MESSAGE_ERROR, L"exe -> get_process_id");
}
void get_process_handle(DWORD process_staet, DWORD process_id, HANDLE& process_handler)
{
	process_handler = OpenProcess(process_staet, FALSE, process_id);
	if (!process_handler)
		error(MESSAGE_ERROR, L" exe -> get_process_handle");
}
template<typename T >
T memory_read(HANDLE process_handle, void* memory_addres) 
{
	T buffer;
	ReadProcessMemory(process_handle, memory_addres, &buffer, sizeof(buffer), NULL);
	return buffer;
}
bool memory_write(HANDLE process_handle, void* memory_addres,int buffer ) 
{
	bool b = WriteProcessMemory(process_handle, memory_addres, &buffer, sizeof(buffer), NULL);
	return b;
}