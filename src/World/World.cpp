//
// Created by Evan on 20/12/12.
//

#include "World.h"

World::World(int ID) {
    this->worldID = ID; // load this world ID from file
    this->initialLoad = 1;
    if (initialLoad) {
        this->generate();
    }
}

void World::generate() {
    // pass
}

void World::generate_new_chunk(glm::vec3 chunk_coord) {
    // superflat chunks
    for (int x = 0; x < 16; ++x) {
        for (int y = 0; y < 10; ++y) {
            for (int z = 0; z < 16; ++z) {
                // add stone;
            }
        }
    }
    for (int x = 0; x < 16; ++x) {
        for (int y = 10; y < 15; ++y) {
            for (int z = 0; z < 16; ++z) {
                // add dirt;
            }
        }
    }
    for (int x = 0; x < 16; ++x) {
        for (int z = 0; z < 16; ++z) {
            // add grass;
        }
    }

}