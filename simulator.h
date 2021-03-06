//
// Created by bhavesh on 2/4/16.
//

#ifndef ENERGYAWAREDC_SIMULATOR_H
#define ENERGYAWAREDC_SIMULATOR_H

#include <queue>

#include "event.h"
#include "datacenter.h"
#include "randomnumbergenerator.h"
#include "utility.h"
#include "configuration.h"

using namespace std;

struct comparator
{
    bool operator()(const Event &e1, const Event &e2)
    {
        return e1.time > e2.time;
    };
};

class Simulator
{
private:
    SimulationTime simulationClockTime;
    priority_queue<Event, vector<Event>, comparator> eventQueue;
    DataCenter dc;
    RandomNumberGenerator rng;
    LogLevel logLevel;

    void MigrateVM(const Event &) ;
    void UpdateEnergyConsumption(const Event &);
    //void HandleMigrationStartEvent(const Event &);
    void PrintStatus(string);

public:
    Simulator();
    ~Simulator();
    int Start();
    void InitializeEventQueue();
    //SimulationTime
    void HandleArrivalEvent( Event &);
    void HandleDepartureEvent( Event &);
    void HandleMigrationCompletionEvent(const Event &);

};
#endif //ENERGYAWAREDC_SIMULATOR_H
