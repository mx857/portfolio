//#include "Header.h"
#include"Admin_class.h"
#include"Login_function.h"


int main() {
    Admin a;
    a.AddAdmin();

    User* loggedInUser = Login();
    if (loggedInUser != nullptr) {
        loggedInUser->DisplayMenu();
    }
    return 0;
}
