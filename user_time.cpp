#include <windows.h>
#include <iostream>
#include <ctime>

int main() {
    FILETIME idle_time, kernel_time, user_time;
    ULONGLONG uptime;
    GetSystemTimes(&idle_time, &kernel_time, &user_time);
    uptime = (reinterpret_cast<ULARGE_INTEGER*>(&kernel_time)->QuadPart + reinterpret_cast<ULARGE_INTEGER*>(&user_time)->QuadPart) / 10000000;
    time_t now = time(nullptr);
    time_t boot_time = now - uptime;
    std::cout << "La computadora se inició a las " << ctime(&boot_time) << std::endl;
    return 0;
}
