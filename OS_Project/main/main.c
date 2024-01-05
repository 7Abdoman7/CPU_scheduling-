#include "main.h"

int main(void) {
    Std_return_t ret = OK;
    processes_t processes_Out;

    ret = app_Start(&processes_Out);

    if (ret == NOT_OK && MAIN_DEBUG_EN) {
        printf("\nError >> Can't start the application @ main\n");
    }
    else {}
    
    return ZERO;
}
