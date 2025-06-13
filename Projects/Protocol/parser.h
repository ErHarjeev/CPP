#ifndef __PARSER
#define __PARSER

#include <fstream>


class Parser
{
    std::ifstream source_file;
    std::ofstream dest_file;
    size_t byte_cout;

    Parser(std::ifstream _source_file, std::ofstream _dest_file, size_t _count);
    Parser(const Parser& other);
    ~Parser();
    bool process_byte();
};

#endif // __PARSER
