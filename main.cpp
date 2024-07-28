#include "includes.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "auth/flux.hpp"
#include "auth/util.hpp"
#include "Windows.h"

void main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, dwMode);
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 400, 400, TRUE);
    SetConsoleTitleA(skCrypt("Crypt").decrypt());
    flux::set_application(skCrypt("clyvz19gd0016ns018tsj2gey").decrypt());

    std::cout << timestamp() << skCrypt("[+] Welcome to Crypt!\n").decrypt();
    Sleep(1000);

    Sleep(1000);

    std::string key;
    std::ifstream keyFile(skCrypt("license.log").decrypt());
    if (keyFile)
    {
        std::getline(keyFile, key);
        keyFile.close();
        system(skCrypt("cls").decrypt());
    }
    else
    {
        std::cout << "> ";
        std::cin >> key;
        std::ofstream newKeyFile(skCrypt("license.log").decrypt());
        newKeyFile << key;
        newKeyFile.close();
        system(skCrypt("cls").decrypt());
    }

    try
    {
        std::cout << timestamp() << skCrypt("[+] Sending Auth Packets...\n").decrypt();
        flux::authenticate(key, getHwid());
        std::cout << timestamp() << skCrypt("[+] Logged In!\n").decrypt();
        Sleep(1000);
    }
    catch (const std::exception&)
    {
        std::cout << timestamp() << skCrypt("Invalid key and/or hwid...\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    std::cout << timestamp() << skCrypt("[+] Waiting for Game..\n").decrypt();
    while (game_wnd == 0)
    {
        Sleep(1);
        mem::process_id = mem::find_process(L"FortniteClient-Win64-Shipping.exe");
        game_wnd = get_process_wnd(mem::process_id);
        Sleep(1);
    }
    system(skCrypt("cls").decrypt());

    if (!librarys::init())
    {
        std::cout << skCrypt("\x1b[31mError code: 1\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    if (!input::init())
    {
        std::cout << skCrypt("\x1b[31mError code: 2\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    if (!gui::init())
    {
        std::cout << skCrypt("\x1b[31mError code: 3\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    if (!mem::find_driver())
    {
        std::cout << skCrypt("\x1b[31mError code: 4\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    virtualaddy = mem::find_image();
    if (!virtualaddy)
    {
        std::cout << skCrypt("\x1b[31mError code: 5\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    cr3 = mem::fetch_cr3();
    if (!cr3)
    {
        std::cout << skCrypt("\x1b[31mError code: 6\nContact staff.\x1B[0m\n").decrypt();
        Sleep(3000);
        exit(0);
    }

    std::cout << timestamp() << skCrypt("dw abt this : ").decrypt() << virtualaddy << "\n";
    std::cout << timestamp() << skCrypt("random numbers dw: ").decrypt() << cr3 << "\n";

    create_overlay();
    directx_init();
    render_loop();
}