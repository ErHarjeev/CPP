// below is in parser.cpp

#include "parser.h"

Parser::Parser(std::ifstream _source_file, std::ofstream _dest_file, size_t _count = 0):
    source_file(_source_file), dest_file(_dest_file), byte_cout(_count)
{
    std::cout<< "Constructor" << source_file << "," << dest_file , << byte_cout;
}

Parser::Parser(const Parser& other)
{
    source_file = other.source_file;
    dest_file   = other.dest_file;
    byte_cout   = other.byte_cout;
    std::cout << "Copy Constructor";
}

Parser::~Parser()
{
    std::cout << "Destructor";
}
