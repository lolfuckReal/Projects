#include "Main.h"

extern void Mappings::commandInit() {
    cK(Command, ({KEY_ENTER_U}), "command-execute");
    cK(Command, ({KEY_MODE_EXIT}), "command-exit");

    cK(Command, ({'a'}), "command-insert-char a");
    cK(Command, ({'b'}), "command-insert-char b");
    cK(Command, ({'c'}), "command-insert-char c");
    cK(Command, ({'d'}), "command-insert-char d");
    cK(Command, ({'e'}), "command-insert-char e");
    cK(Command, ({'f'}), "command-insert-char f");
    cK(Command, ({'g'}), "command-insert-char g");
    cK(Command, ({'h'}), "command-insert-char h");
    cK(Command, ({'i'}), "command-insert-char i");
    cK(Command, ({'j'}), "command-insert-char j");
    cK(Command, ({'k'}), "command-insert-char k");
    cK(Command, ({'l'}), "command-insert-char l");
    cK(Command, ({'m'}), "command-insert-char m");
    cK(Command, ({'n'}), "command-insert-char n");
    cK(Command, ({'o'}), "command-insert-char o");
    cK(Command, ({'p'}), "command-insert-char p");
    cK(Command, ({'q'}), "command-insert-char q");
    cK(Command, ({'r'}), "command-insert-char r");
    cK(Command, ({'s'}), "command-insert-char s");
    cK(Command, ({'t'}), "command-insert-char t");
    cK(Command, ({'u'}), "command-insert-char u");
    cK(Command, ({'v'}), "command-insert-char v");
    cK(Command, ({'w'}), "command-insert-char w");
    cK(Command, ({'x'}), "command-insert-char x");
    cK(Command, ({'y'}), "command-insert-char y");
    cK(Command, ({'z'}), "command-insert-char z");
    cK(Command, ({'A'}), "command-insert-char A");
    cK(Command, ({'B'}), "command-insert-char B");
    cK(Command, ({'C'}), "command-insert-char C");
    cK(Command, ({'D'}), "command-insert-char D");
    cK(Command, ({'E'}), "command-insert-char E");
    cK(Command, ({'F'}), "command-insert-char F");
    cK(Command, ({'G'}), "command-insert-char G");
    cK(Command, ({'H'}), "command-insert-char H");
    cK(Command, ({'I'}), "command-insert-char I");
    cK(Command, ({'J'}), "command-insert-char J");
    cK(Command, ({'K'}), "command-insert-char K");
    cK(Command, ({'L'}), "command-insert-char L");
    cK(Command, ({'M'}), "command-insert-char M");
    cK(Command, ({'N'}), "command-insert-char N");
    cK(Command, ({'O'}), "command-insert-char O");
    cK(Command, ({'P'}), "command-insert-char P");
    cK(Command, ({'Q'}), "command-insert-char Q");
    cK(Command, ({'R'}), "command-insert-char R");
    cK(Command, ({'S'}), "command-insert-char S");
    cK(Command, ({'T'}), "command-insert-char T");
    cK(Command, ({'U'}), "command-insert-char U");
    cK(Command, ({'V'}), "command-insert-char V");
    cK(Command, ({'W'}), "command-insert-char W");
    cK(Command, ({'X'}), "command-insert-char X");
    cK(Command, ({'Y'}), "command-insert-char Y");
    cK(Command, ({'Z'}), "command-insert-char Z");
    cK(Command, ({' '}), "command-insert-char SPC");
    cK(Command, ({'-'}), "command-insert-char -");
    cK(Command, ({KEY_BACKSPACE_U}), "command-pop-char");
}
