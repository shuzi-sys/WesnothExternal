#include <windows.h>

int main() {
	HWND wesnothWindow = FindWindow(NULL, L"La batalla por Wesnoth - 1.14.9");
	DWORD wesnothId = NULL;
	GetWindowThreadProcessId(wesnothWindow, &wesnothId);
	HANDLE wesnothHandle = OpenProcess(PROCESS_ALL_ACCESS, true , wesnothId);
	DWORD gold_value = 0;
	DWORD bytes_read = 0;
	ReadProcessMemory(wesnothHandle, (void*)0x017EED18, &gold_value, 4, &bytes_read);

	gold_value += 0XA90;
	ReadProcessMemory(wesnothHandle, (void*)gold_value, &gold_value, 4, &bytes_read);
	gold_value += 4;

	DWORD new_gold_Value = 555;
	DWORD bytes_written = 0;
	WriteProcessMemory(wesnothHandle, (void*)gold_value, &new_gold_Value, 4, &bytes_written);

	return 0;
}