/* (c) Copyright 2018, Nirav Doshi */
/* This code is licensed under MIT license. */

#include "generateData.h"

unsigned long int    clRPGPlayers::ulRPGPlayerCount = 0UL;
unsigned long int    clRPGPlayers::ulRPGFraudPlayerCount = 0UL;

//------------------------------------------------------------------------------
int main(void)
{
    unsigned long int	ulTotalPlayers;
    unsigned short      usFraudPercentage;
    unsigned long int   ulGamePlayRecordCount;

    cout << "--- How many RPG players data to be generated?: ";
    cin  >> ulTotalPlayers;

    cout << "--- Maximum percentage of fraudulent data to be generated? (0 to 100): ";
    cin  >> usFraudPercentage;

    cout << "--- How many game play log entries to generate?: ";
    cin >> ulGamePlayRecordCount;

    while(ulTotalPlayers-- > 0UL)
    {
    	clRPGPlayers::generateOnePlayer();
    }

    cout << endl << "--- Generated " << clRPGPlayers::ulRPGPlayerCount << " RPG players..." << endl;
    clRPGPlayers::markFraudPlayers(usFraudPercentage);
    cout << "--- Fraud Player Count: " << clRPGPlayers::ulRPGFraudPlayerCount << "..." << endl;

    cout << endl << "--- Dumping players list..." << endl;
    clRPGPlayers::dumpPlayersList();

    cout << endl << "--- Generated " << clRPGPlayers::ulRPGPlayerCount << " RPG players..." << endl;
    cout << "--- Fraud Player Count: " << clRPGPlayers::ulRPGFraudPlayerCount << "(" << fixed << setprecision(2) << static_cast<float>((clRPGPlayers::ulRPGFraudPlayerCount * 100.00f)/clRPGPlayers::ulRPGPlayerCount) << "%)..." << dec << endl;

    clPlayerRPGameData *ptrPlayerRPGameData = clPlayerRPGameData::getInstance(ulGamePlayRecordCount);
    ptrPlayerRPGameData->generatePlayerGamePlayData();

    cout << endl << "--- Dumping players list..." << endl;
    clRPGPlayers::dumpPlayersList();

    cout << endl << "--- Generated " << clRPGPlayers::ulRPGPlayerCount << " RPG players..." << endl;
    cout << "--- Fraud Player Count: " << clRPGPlayers::ulRPGFraudPlayerCount << "(" << fixed << setprecision(2) << static_cast<float>((clRPGPlayers::ulRPGFraudPlayerCount * 100.00f)/clRPGPlayers::ulRPGPlayerCount) << "%)..." << dec << endl;

    cout << endl << "--- Cleaning up players list..." << endl;
    clRPGPlayers::dropPlayersList();
    cout << endl << "--- Done. Bye." << endl;

    return 0;
}
