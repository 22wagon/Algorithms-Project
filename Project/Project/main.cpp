#include "menu.hpp"

int main () {
  Menu *main_menu = new Menu();
  int menu_output = 0;
  menu_output = main_menu->Start();

  delete main_menu;

  return menu_output;
}

