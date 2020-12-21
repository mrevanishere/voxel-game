//
// Created by Evan on 20/12/12.
//

#include "ChunkManager.h"

const std::string FULL_PATH = "C:/gith/__inactive/c++/OpenGLExperiementVoxel/resources/saves/default/world1/chunk.data";
const std::string CHUNK_PATH = "../../resources/saves/default/world1/chunk.csv";
const std::string SCUFFED_PATH = "C:/gith/mrevanishere/blocksandsticks/resources/saves/default/world1/newchunk.data";
const std::string NEW_CHUNK = "../../resources/saves/default/world1/newchunk.data";

ChunkManager::ChunkManager(glm::vec3 camera_chunk_pos) {
    // replace this with spiral when ready
    int render_region = render_distance*2 + 1;
    for (int x = 0; x < render_region; ++x) {
        for (int z = 0; z < render_region; ++z) {
            chunks.emplace_back(Chunk(glm::vec3((camera_chunk_pos.x - render_distance-1) + x, 2, (camera_chunk_pos.z - render_distance-1) + z)));
        }
    }
    for (int i = 0; i < chunks.size(); ++i) {
        load(chunks[i]);
    }
    std::cout << "CM Constructor Complete" << std::endl;
}

void ChunkManager::update(Shader &shader, glm::vec3 camera_chunk_pos, glm::vec3 previous_chunk_position) {
    // analysis: O((R+1)^2) + O((R+1)^2) + O((R+1)^2)

    if (camera_chunk_pos == previous_chunk_position) {
        for (int i = 0; i < chunks.size(); ++i) {
            // load(c); // we shouldn't have to do this unless i'm mis understanding
            // std::cout << c.chunk_pos.x << c.chunk_pos.y << c.chunk_pos.z << std::endl;
            chunks[i].draw(shader);
        }
    } else {
        std::cout << "curr: "
                  << " x: " << camera_chunk_pos.x
                  << " y: " << camera_chunk_pos.y
                  << " z: " << camera_chunk_pos.z << std::endl;
        std::cout << "prev: "
                  << " x: " << previous_chunk_position.x
                  << " y: " << previous_chunk_position.y
                  << " z: " << previous_chunk_position.z << std::endl;

        // chunk_pos in render_distance
        std::vector<glm::vec3> load_list;
        int render_region = render_distance*2 + 1;
        for (int x = 0; x < render_region; ++x) {
            for (int z = 0; z < render_region; ++z) {
                load_list.emplace_back(glm::vec3((camera_chunk_pos.x - render_distance) + x, 2, (camera_chunk_pos.z - render_distance) + z));
            }
        }

        // if chunks on the outside this is for which chunks need to be created
        std::vector<int> indices;
        // change this to std::iota
        for (int i = 0; i < load_list.size(); ++i) {
            indices.push_back(i);
        }

        // in chunk but not in list then remove chunk else draw
        for (int i = 0; i < chunks.size(); ++i) {
            bool chunk_in_list = false;
            int j = 0;
            while (j < load_list.size()) {
                if (chunks[i].chunk_pos == load_list[j]) {
                    // remove from indices
                    chunk_in_list = true;
                    break;
                }
                ++j;
            }
            if (!chunk_in_list) {
                chunks.erase(chunks.begin() + i);
                --i;
            } else {
                indices.erase(std::find(indices.begin(), indices.end(), j));
                load(chunks[i]);
                chunks[i].draw(shader);
            }

        }

        // in loadlist but not in chunks: undrawn
        int offset = chunks.size();
        for (int i = 0; i < indices.size(); ++i) {
            chunks.emplace_back(Chunk(load_list[indices[i]]));
            load(chunks[offset + i]);
            chunks[offset + i].draw(shader);
        }
        std::cout << "CM Update done" << std::endl;
    }
}

void ChunkManager::load(Chunk &c) {
    if (c.loaded) {
        return;
    }
    bool has_chunk = chunkBuffer.count((c.chunk_pos.x + (c.chunk_pos.y * 16) + (c.chunk_pos.z * 16 * 16)));
    if (has_chunk) {
        c.update_buffer(chunkBuffer.at((c.chunk_pos.x + (c.chunk_pos.y * 16) + (c.chunk_pos.z * 16 * 16))));
    } else {
        // c.default(); // c.world_gen();
    }
    c.gen_buffer();
    c.loaded = true;
    // std::cout << " loaded ";
}

void ChunkManager::read() {
    std::vector<int> chunk_data;
    std::vector<int> chunk_pos;
    int flat_chunk_pos;
    // read file and spit out data
    std::ifstream infile(FULL_PATH);
    if (!infile.good()) {
        std::cout << "Failed to open" << std::endl;
        return;
    }
    std::cout << "File Loaded" << std::endl;

    // while not end of file
    // get chunk pos
    // for < 256
    // for < 32

    int c = 1;
    int z = 1;
    int y = 1;
    while (!infile.eof()) {
        // read file
        std::string line;
        getline(infile, line);
        //std::cout << c << ": " << line << std::endl;
        if (line.empty()) {
            // find a different solution for this
            std::cout << "End of File" << std::endl;
            break;
        }
        if (!infile.good()) {
            std::cout << "bad file" << std::endl;
            break;
        }
        // read chunk
        int i = 0;
        std::stringstream issChunk(line);
        std::string pos;
        while (getline(issChunk, pos, ',') && i < 3) {
            i++;
            //std::cout << pos << std::endl;
            chunk_pos.push_back(std::stoi(pos));
        }
        // chunk_pos to 1d
        flat_chunk_pos = chunk_pos[0] + (chunk_pos[1] * 16) + (chunk_pos[2] * 16 * 16);
        // read block data
        for (int l = 0; l < 256; ++l) {
            getline(infile, line);
            //std::cout << "y" << y << " z" << z << ": " << line << std::endl;
            if (z % 16 == 0) {
                z = 0;
                ++y;
//                std::cout << "y" << y << ": " << std::endl;
            }
            for (int x = 0; x < 16; ++x) {
                std::stringstream iss(line);
                std::string val;
                getline(iss, val, ',');
                if (!iss.good()) {
                    std::cout << "bad stream" << std::endl;
                    break;
                }
                chunk_data.push_back(std::stoi(val));
            }
            ++z;
        }
        ++c;
        y = 1;
        z = 1;
    }
    chunkBuffer.insert(std::pair<int, std::vector<int>>(flat_chunk_pos, chunk_data));
    std::cout << "File Read" << std::endl;
    return;
}

void ChunkManager::write() {
    // write values
    //    std::ofstream ofile;
    //    ofile.open(SCUFFED_PATH);
    //    if (!ofile.good()) {
    //            std::cout << "won't write" << std::endl;
    //            return;
    //    }
    //    for (int i = 0; i < chunkData.size(); ++i) {
    //        for (int j = 0; j < chunkData[0].size(); ++j) {
    //            // ofile << chunkData[chunk][y][z][x] << ",";
    //        }
    //        ofile << "\n";
    //    }
    //    ofile.close();
    return;
}

ChunkManager::~ChunkManager() = default;