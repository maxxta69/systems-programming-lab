#include <iostream>
#include <fstream>

bool copy_stream(std::istream& in, std::ostream& out){
    constexpr std::streamsize BUFFER_SIZE = 65535;
    char buffer[BUFFER_SIZE];
    while(in.read(buffer, BUFFER_SIZE) || in.gcount() > 0){
        out.write(buffer, in.gcount());
    }
    return !in.bad();
}

int main(int argc, char** argv){
    
    bool ok = true;

    if(argc == 1){
        return  copy_stream(std::cin, std::cout)? 0: 1;
    }

    for (int i = 1; i < argc; i++){
        std::string filename = argv[i];
        std::ifstream inFile(filename, std::ios::binary);
        if(!inFile.is_open()){
            std::cerr << "Unable to open file: " << filename << '\n';
            ok = false;
            continue;
        }

        if(!copy_stream(inFile, std::cout)) ok = false;

        inFile.close();
    }

        return ok? 0 : 1;
}