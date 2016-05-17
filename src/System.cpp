#include "../include/System.h"

#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"


void System::setUp() {
    SourceLane* left = new SourceLane{2000, 90, 0, 0};
    ConsumerLane* right = new ConsumerLane{400, 48};
    Semaphore* s = new Semaphore{20, left};
    lane_.pushBack(left);
    lane_.pushBack(right);
    sem_.pushBack(s);

    for (int i = 0; i < sem_.size(); ++i) {
        Semaphore* s = sem_.at(i);
        handler_.schedule(Event{0, kChangeSemaphore, (void*) s});
    }

    for (int i = 0; i < lane_.size(); ++i) {
        Lane* l = lane_.at(i);
        handler_.schedule(Event{0, kSpawnVehicle, (void*) l});
    }
}

void System::run() {

}