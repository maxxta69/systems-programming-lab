#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

struct Count {
    std::streamsize lines = 0;
    std::streamsize words = 0;
    std::streamsize bytes = 0;
};

bool count_stats(std::istream& in, Count& count){
    constexpr std::streamsize BUFFER_SIZE = 65535;
    char buffer[BUFFER_SIZE];
    bool in_word = false;
    while(in.read(buffer, BUFFER_SIZE) || in.gcount() > 0){
        std::streamsize byte_size = in.gcount();
        for (std::streamsize i = 0; i < byte_size; i++){
            unsigned char ch = static_cast<unsigned char>(buffer[i]);
            if(ch == '\n'){
                count.lines++;
            }
            if(std::isspace(ch)){
                in_word = false;
            }
            else if(!in_word){
                in_word = true;
                count.words++;
            }
        }
        count.bytes += in.gcount();
    }
    return !in.bad();
}

int main(int argc, char** argv){

    bool ok = true;
    Count total;

    if(argc == 1){
        Count count;
        if(count_stats(std::cin, count) == false){
            std::cerr << "An error occurred!" << std::endl;
            return 1;
        }
        std::cout << std::setw(8) << count.lines
                  << std::setw(8) << count.words
                  << std::setw(7) << count.bytes << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++){
        Count count;
        std::string filename = argv[i];
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile.is_open())
        {
            std::cerr << "Unable to open file: " << filename << std::endl;
            ok = false;
            continue;
        }
        if(count_stats(inFile, count) == false){
            std::cerr << "Unable to open file: " << filename << std::endl;
            ok = false;
            continue;
        }
        total.bytes += count.bytes;
        total.words += count.words;
        total.lines += count.lines;
        std::cout << std::setw(8) << count.lines
                  << std::setw(8) << count.words
                  << std::setw(7) << count.bytes
                  << " " << filename << std::endl;
    }
    if(argc > 2){
        std::cout << std::setw(8) << total.lines
                  << std::setw(8) << total.words
                  << std::setw(7) << total.bytes
                  << " total" << std::endl;
    }

    return ok ? 0 : 1;
}