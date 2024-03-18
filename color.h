
/* Header file containing functions for changing color. */

#include<iostream>
using namespace std;

void reset()   { cout << "\033[0m";    }

// Dark Color Functions:
void DBlack()  { cout << "\e[1;30m"; }
void DRed()    { cout << "\033[1;31m"; }
void DGreen()  { cout << "\033[1;32m"; }
void DYellow() { cout << "\033[1;33m"; }
void DBlue()   { cout << "\033[1;34m"; }
void DPurple() { cout << "\033[1;35m"; }
void DCyan()   { cout << "\033[1;36m"; }
void DWhite()  { cout << "\033[1;37m"; }

//Light Color Functions:
void LBlack()  { cout << "\033[0;30m"; }
void LRed()    { cout << "\033[0;31m"; }
void LGreen()  { cout << "\033[0;32m"; }
void LYellow() { cout << "\033[0;33m"; }
void LBlue()   { cout << "\033[0;34m"; }
void LPurple() { cout << "\033[0;35m"; }
void LCyan()   { cout << "\033[0;36m"; }
void LWhite()  { cout << "\033[0;37m"; }

//Underline Color Functions:
void UBlack()  { cout << "\033[4;30m"; }
void URed()    { cout << "\033[4;31m"; }
void UGreen()  { cout << "\033[4;32m"; }
void UYellow() { cout << "\033[4;33m"; }
void UBlue()   { cout << "\033[4;34m"; }
void UPurple() { cout << "\033[4;35m"; }
void UCyan()   { cout << "\033[4;36m"; }
void UWhite()  { cout << "\033[4;37m"; }

//Background:
void BBlack()  { cout << "\033[40m"; }
void BRed()    { cout << "\033[41m"; }
void BGreen()  { cout << "\033[42m"; }
void BYellow() { cout << "\033[43m"; }
void BBlue()   { cout << "\033[44m"; }
void BPurple() { cout << "\033[45m"; }
void BCyan()   { cout << "\033[46m"; }
void BWhite()  { cout << "\033[47m"; }

//High Intensity:
void HIBlack()  { cout << "\033[0;90m"; }
void HIRed()    { cout << "\033[0;91m"; }
void HIGreen()  { cout << "\033[0;92m"; }
void HIYellow() { cout << "\033[0;93m"; }
void HIBlue()   { cout << "\033[0;94m"; }
void HIPurple() { cout << "\033[0;95m"; }
void HICyan()   { cout << "\033[0;96m"; }
void HIWhite()  { cout << "\033[0;97m"; }

//Bold High Intensity:
void DHI_Black()  { cout << "\033[1;90m"; }
void DHI_Red()    { cout << "\033[1;91m"; }
void DHI_Green()  { cout << "\033[1;92m"; }
void DHI_Yellow() { cout << "\033[1;93m"; }
void DHI_Blue()   { cout << "\033[1;94m"; }
void DHI_Purple() { cout << "\033[1;95m"; }
void DHI_Cyan()   { cout << "\033[1;96m"; }
void DHI_White()  { cout << "\033[1;97m"; }

//High Intensity Backgrounds:
void HIB_Black()  { cout << "\033[0;100m"; }
void HIB_Red()    { cout << "\033[0;101m"; }
void HIB_Green()  { cout << "\033[0;102m"; }
void HIB_Yellow() { cout << "\033[0;103m"; }
void HIB_Blue()   { cout << "\033[0;104m"; }
void HIB_Purple() { cout << "\033[0;105m"; }
void HIB_Cyan()   { cout << "\033[0;106m"; }
void HIB_White()  { cout << "\033[0;107m"; }

