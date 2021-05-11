//-----------------------------------------------------------------------------
/// @file
/// The main() for the 1350analayis application running in the instrument.
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <boost/program_options.hpp>
#include <iostream>

//-----------------------------------------------------------------------------
// Globals, Constants, Defines, Macros, Forward References
//-----------------------------------------------------------------------------
namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()("help", "produce help message")("simulate", "Run with simulated instrument.");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help"))
    {
        std::cout << desc << "\n";
        return 1;
    }

    bool fSimulator = false;
    if(vm.count("simulate"))
    {
        std::cout << "Running Simulator.\n";
        fSimulator = true;
    }

    std::cout << "Hello World!\n";
    return 0;
}
